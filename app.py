from flask import Flask, render_template, request, redirect, url_for, flash

app = Flask(__name__)
app.secret_key = 'econald'

# 초기 브랜드 값 설정
starbucks_count = 0
ediya_count = 0
twosome_count = 0
baek_count = 0
mega_count = 0
compose_count = 0

@app.route('/')
def index():
    # 현재 브랜드 값 전달
    return render_template('index.html')

@app.route('/update', methods=['GET','POST'])
def update():
    # 사용자로부터 입력된 문자열 받기
    global starbucks_count, ediya_count, twosome_count, baek_count, mega_count, compose_count
    if request.method == 'POST':
        user_input = request.form.get('user_input')
    print("Reveived data",user_input)
    # 입력된 문자열에 해당하는 브랜드 값 증가
    if user_input == 'starbucks':
        starbucks_count += 1
    elif user_input == 'ediya':
        ediya_count += 1
    elif user_input == 'twosome':
        twosome_count += 1
    elif user_input == 'baek':
        baek_count += 1
    elif user_input == 'mega':
        mega_count += 1
    elif user_input == 'compose':
        compose_count += 1


    # 업데이트된 브랜드 값 전달
    return render_template('page5a.html', starbucks=starbucks_count, ediya=ediya_count, twosome=twosome_count, baek=baek_count, mega=mega_count, compose=compose_count)


@app.route('/page1.html')
def next_page():
    return render_template('page1a.html') #,starbucks=starbucks_count, ediya=ediya_count, twosome=twosome_count, baek=baek_count, mega=mega_count, compose=compose_count)

@app.route('/page2.html')
def another_next_page():
    return render_template('page2.html')

@app.route('/page3.html')
def another3_page():
    return render_template('page3.html')
@app.route('/page4.html')
def another4_page():
    return render_template('page4.html')
@app.route('/page5.html')
def another5_page():
    return render_template('page5.html')
@app.route('/page6.html')
def another6_page():
    return render_template('page6.html')
@app.route('/page7.html')
def another7_page():
    global starbucks_count, ediya_count, twosome_count, baek_count, mega_count, compose_count
    return render_template('page7.html', 
                           starbucks=starbucks_count, 
                           ediya=ediya_count, 
                           twosome=twosome_count, 
                           baek=baek_count, 
                           mega=mega_count, 
                           compose=compose_count)
@app.route('/page8.html')
def another8_page():
    return render_template('page8.html')

@app.route('/page1a.html')
def another_region1_page():
    return render_template('page1a.html')
@app.route('/page2a.html')
def another_region2_page():
    return render_template('page2a.html')
@app.route('/page3a.html')
def another_region3_page():
    return render_template('page3a.html')
@app.route('/page4a.html')
def another_region4_page():
    return render_template('page4a.html')
@app.route('/page5a.html')
def another_region5_page():
    global starbucks_count, ediya_count, twosome_count, baek_count, mega_count, compose_count
    return render_template('page5a.html', 
                           starbucks=starbucks_count, 
                           ediya=ediya_count, 
                           twosome=twosome_count, 
                           baek=baek_count, 
                           mega=mega_count, 
                           compose=compose_count)
@app.route('/page6a.html')
def another_region6_page():
    return render_template('page6a.html')


@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']

    if username == 'cisco' and password == 'love':
        return redirect(url_for('bankstart'))
    else:
        flash('로그인 실패! 아이디나 비밀번호를 확인하세요.')
        return redirect(url_for('qrlogin'))

@app.route('/qrlogin.html')
def qrlogin():
    return render_template('qrlogin.html')
@app.route('/bankstart.html')
def bankstart():
    return render_template('bankstart.html')
@app.route('/end.html')
def end():
    return render_template('end.html')

@app.route('/delay.html')
def delay():
    return render_template('delay.html')




if __name__ == '__main__':
    app.run(debug=True)
