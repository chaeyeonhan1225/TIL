# **http 모듈 사용하기**

- 클라이언트는 서버로 **요청** 을 보낸다.
- 서버는 요청의 내용을 읽고 처리한 뒤 클라이언트에게 **응답**을 보낸다.

서버에는 요청을 받는 부분과 응답을 보내는 부분이 필요

요청과 응답은 **이벤트**방식

- createSever 메서드

인자로 요청에 대한 콜백 함수를 넣는다.
```javascript
const http = require('http');

http.createSever((req,res)=>{
    // 응답을 보냄
});
```
- 서버 연결

createSever 메서드 뒤에 **listen 메서드**를 붙이고 인자로 **포트 번호**와 포트 연결 완료 후 실행될
**콜백 함수**를 넣어줌 (test용으로 8080을 많이씀)

```javascript
const http = require('http');

http.createSever((req,res)=>{
    res.write();
}).listen(8080,()=>{
    console.log('8080포트에서 서버 대기 중');
});
```

**listening 이벤트 리스너**를 붙여도 됨

```javascript
const http = require('http');

const server = http.createSever((req,res)=>{
    res.write('');
});

server.listen(8080);
server.on('listening',()=>{
    console.log('8080포트에서 서버 대기 중');
});
server.on('error',(error)=>{
    console.error(error);
}); // error 이벤트 리스너
```

## **res객체**

1. ``res.write ``
 
 첫 번째 인자는 클라이언트로 보낼 데이터

 버퍼를 보낼 수도 있다. 여러 번 호출해서 데이터를 여러 개 보낼 수 있다.

2. ``res.end``

 응답을 종료하는 메서드
 
 만약 인자가 있다면 그 데이터도 클라이언트로 보내서 응답을 종료

 브라우저는 응답 내용을 받아서 렌더링 한다.



> **포트**

포트는 서버 내에서 프로세스를 구분하는 번호

서버는 HTTP 요청을 대기하는 것 외에도 다양한 작업을 하므로 데이터베이스와도 통신해야 하고, FTP 요청을 처리하기도 함

따라서 서버는 프로세스에 포트를 다르게 할당하여 들어오는 요청을 구분함

21(FTP),80(HTTP),443(HTTPS),3306(MYSQL)

포트 번호는 IP 주소 뒤에 콜론(:)과 함께 붙여 사용

---

## **참조**

Node.js 교과서 
