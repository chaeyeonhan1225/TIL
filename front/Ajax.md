# ***AJAX***

> AJAX 란?

- Ajax는 JavaScript의 라이브러리 중 하나이며 **Asynchronous JavaScript And Xml (비동기식 자바스크립트와 xml)**의 약자이다.
- 브라우저가 가지고 있는 **XMLHttpRequest** 객체를 이용해서 **전체 페이지를 새로 고치지 않고도 페이지 일부만을 위한 데이터를 로드**하는 기법
- JavaScript를 사용한 비동기 통신, 클라이언트와 서버간에 XML 데이터를 주고받는 기술

> 처리 과정

<pre><code>var xhr = new XMLHttpRequest;
xhr.open('요청메서드','요청 주소');
xhr.send('내용');</code></pre>

> 예외 처리

- JavaScript

<pre><code>xhr.readyState === XMLHttpRequest.DONE
xhr.status===200</code></pre>

> jQuery

<pre><code>$.ajax({
    type: 'http 전송 method 지정'
    url: '호출 url'
    datatype: 'ajax을 통해 호출한 페이지의 return 형식'
    error: '에러났을때의 처리 부분'
    success: '성공했을때의 처리부분'
});</code></pre>

<hr>

**Reference**

- 네이버 블로그 현재를 즐겨라
https://blog.naver.com/cpfl0911/221742527608

- 네이버 블로그 Smart Life & Computer Climbing
https://blog.naver.com/wj8606/221206304635

