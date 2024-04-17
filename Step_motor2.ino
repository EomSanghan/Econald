//--------------------------------------------------------------------------------
//File name: Step_Motor
//ver 1.8.19
//<Abstrcact>
//스텝 모터 컨트롤 두개 다루기
//Full Step 방식: Step per 1.8degree
//
//<Connection Info>
//---------------------------------------------------------------------------------
//      Arduino                         DRV8825                       17HD5003(2)                       
//---------------------------------------------------------------------------------
//         -                       EN'         VMOT                     12V
//         -                       MS1         GND                      GND
//         -                       MS2         B2                       BLUE
//         -                       MS3         B1                       RED
//        5V                       RESET'      A1                       Black
//        5V                       SLEEP'      A2                       Green
//         PB2(10)                 Step        FAULT                    
//         PB3(11)                 DIR         GND                      GND
//---------------------------------------------------------------------------------
//      Arduino                         DRV8825                       17HD5003(1)                    
//---------------------------------------------------------------------------------
//         -                       EN'         VMOT                     12V
//         -                       MS1         GND                      GND
//         -                       MS2         2B                       BLUE
//         -                       MS3         2A                       RED
//        5V                       RESET'      1A                       Black
//        5V                       SLEEP'      1B                       Green
//         PB1(9)                 Step        FAULT                     
//         PB0(8)                 DIR         GND                      GND
//---------------------------------------------------------------------------------
// SUNFOUNDER Servo Motor를 사용하면 전합 강하에 의한 포트 연결이 끊기는 경우가 발생
// 외부 전원을 사용하라는 의견이 있음


#define STEP_1 2
#define DIR_1 3
#define STEP_2 1
#define DIR_2 0

// 모터속도
#define STEP1_SPEED 3000
#define STEP2_SPEED 3000

// 일정 주기 마다 loop문이 동작하게 만들기 위한 변수들
//-----------------------------------------------------------------------------------
float ts = 0.01;              // Sample Time
float Time = 0.0;             // 현재 시간
uint32_t MicrosSampleTime;    // us단위의 Sample Time
uint32_t time_out;            // 현재 시간을 update


// Step Motor1
volatile unsigned char cmd;

// Step Motor2
//volatile int loc[6] = {0, 533, 1066, 1600, 2133, 2666};
//volatile unsigned char current_loc = 0;
//volatile unsigned char rad = 0;
//volatile int moving = 0;

// Receive interrupt
ISR(USART_RX_vect){    
   cmd = UDR0;     // get received data

   if(cmd & 0b10000000){     // 8번 비트만 확인 위해서  & 사용
      PORTB |= (1<<DIR_1);   // counter clockwise
      for(int x = 0; x < 200; x++){
        PORTB |= (1<<STEP_1); 
        delayMicroseconds(STEP1_SPEED); 
        PORTB &= ~(1<<STEP_1); 
        delayMicroseconds(STEP1_SPEED);  // 시계 방향 회전
      }
   }
   else if(cmd & 0b01000000){ // 밑에 스텝모터 회전, 알맞는 브랜드에.

      rad = cmd & 0b00111111; // 파이썬에서 넘어온 바이트 확인하기

      PORTB |= (1<<DIR_2);   // counter clockwise
      for(int x = 0; x < 33*rad; x++){
        PORTB |= (1<<STEP_2); 
        delayMicroseconds(STEP1_SPEED); 
        PORTB &= ~(1<<STEP_2); 
        delayMicroseconds(STEP1_SPEED); 
      }
   }
   UDR0 = 'a';
}


void setup() {
  // USART0 Communication
  // Datasheet 227p~235p
  UCSR0A |= _BV(U2X0);    // 2배속 모드,_BV는 해당 비트만 1로 하고 나머지 비트 0으로 하는 비트 마스크 생성.

  UBRR0H = 0x00;
  UBRR0L = 207;           // 통신 보율 설정, UBRRx는 12비트 레지스터로 H(4),L(8) 존재.

  UCSR0C |= 0x06;         // 비동기, 8비트 데이터, 패리티 없음, 1비트 정지 비트 모드

  UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); // 송수신 가능, RXCIE0(수신 인터럽트 활성화)
  sei();

  DDRB |= (1<<STEP_1) | (1<<DIR_1);

  DDRB |= (1<<STEP_2) | (1<<DIR_2);

}

void loop() {
  
}