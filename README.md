
# Econald's

## Team Members

| 윤제화 | 엄상한 | 이준화 | 정현우 | 이상우 | 윤준혁 |
|:------|:------|:------|:------|:------|:------|

![Background Image](/econald.png)

## 기능 개요

- 이미지 처리 및 객체 탐지: YOLOv5를 사용하여 이미지 내 객체를 식별 분류
- 웹 서버 및 API: Flask를 사용하여 YOLOv5로 처리된 결과를 서비스하는 REST API를 구축
- 모터 제어: C++을 사용하여 스텝 모터를 제어
- 데이터 시각화: JavaScript와 D3.js를 활용하여 맵 기반의 상호 작용적인 데이터 시각화를 구현
- 웹 페이지 인터페이스: HTML과 CSS를 사용하여 사용자 인터페이스를 구성
- 시뮬레이션: 하드웨어 설계를 대신할, NX Assembly Sequency가 실행되면 설계 기기의 각 부품(Cam 및 Stack plate)이 제어되어 입력된 동작을 수행합니다.

## 기술 스택
<div style="display: flex;">
    <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=Python&logoColor=white">
    <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=C++&logoColor=white">
    <img src="https://img.shields.io/badge/D3.JS-F9A03C?style=for-the-badge&logo=D3.js&logoColor=white">
    <img src="https://img.shields.io/badge/Javascript-F7DF1E?style=for-the-badge&logo=Javascript&logoColor=white">
    <img src="https://img.shields.io/badge/NX-143055?style=for-the-badge&logo=NX&logoColor=white">
</div>


### Python
- **YOLOv5**: 실시간 객체 탐지
- **Flask**: 웹 애플리케이션 프레임워크

### C++
- **스텝 모터 제어**: ISR을 호출하여, 파이썬에서 보낸 값만큼 모터를 제어.

### JavaScript
- **D3.js**: JavaScript 라이브러리를 통해 지도 시각화.

### HTML/CSS
- **웹 페이지 레이아웃**: 프로젝트의 프론트엔드 인터페이스.

### NX
- **NX Program Assembly Sequency**: 객체 탐지 후 브랜드가 인식되면, 해당 브랜드에 해당하는 NX program 내의 animation sequency가 실행됩니다.




## 프로젝트 파일 구조 및 설명

### **app.py, templates, static**
Flask 서버 및 웹페이지 코드를 포함하고 있습니다. `app.py`는 서버의 백엔드 로직을 처리하고, `templates` 폴더에는 HTML 페이지 템플릿이, `static` 폴더에는 CSS 파일과 JavaScript 파일 저장되어 있습니다.<br>
- **page1a, page2a, ...**: 이 페이지들은 특정 표를 보여줍니다.

- **page1, page2, ...**: 이 페이지들은 D3.js를 활용한 인터랙티브 지도를 표시합니다.


> **참고**: 객체 인식 후 웹 페이지의 값을 증가시키기 위해, `Cisco project.ipynb`의 ipynb 코드 내에서 엔드포인트 페이지 주소를 변경해야 합니다. 현재는 저의 pythonanywhere 주소로 되어있습니다.

### **Cisco project.ipynb**
yolov5를 이용한 객체 탐지 코드가 포함되어 있습니다. <br>

> **참고**: 실행하시려면, NX와 Arduino 시리얼에 관련된 코드를 주석을 추가처리하거나 제거함으로써 실행이 가능합니다.

### **step_motor2.ino**
이 파일은 스텝 모터 제어를 위한 C++ 코드입니다. 

### **NX Cisco Assembly Sequency Modelling file**
이 파일은 시뮬레이션에 해당하는 NX modeling 파일입니다.

---

