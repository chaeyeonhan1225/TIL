# **노드의 fs모듈**

## fs모듈

fs 모듈은 파일 시스템에 접근하는 모듈

### fs모듈의 메서드

> **readFile**

```javascript
const fs = require('fs');
fs.readFile('파일이름',(err,data)=>{
    // 콜백 함수
});
```

콜백 함수의 매개변수로 에러 또는 데이터를 받는다.

버퍼라는 형식으로 리턴

toString()으로 문자열로 변환해 주면된다.

> **writeFile**

```javascript
const fs = require('fs');
fs.writeFile('파일이름',(err)=>{
    // 콜백 함수
});
```

## Buffer 클래스

- from(문자열) : 문자열을 버퍼로 바꿈
- toString(버퍼) : 버퍼를 문자열로 바꿈 (base64,hex를 인자로 넣어 해당 인코딩으로 변환할 수도 있음)
- concat(배열) : 배열 안에 든 버퍼들을 하나로 합침
- alloc(바이트) : 인자로 지정해준 바이트의 크기를 가진 빈 버퍼를 생성

## Stream

**버퍼의 크기를 작게 만들어서 여러 번에 나눠서 보내는 방식**

> createReadStream

```javascript
const fs = require('fs');
const readStream = fs.createStream('read.txt',{highWaterMark:16});
```

createStream('읽을 파일 경로','옵션객체');

highWaterMark옵션: 버퍼의 크기를 정할 수 있음(바이트 단위)

> readStream

```javascript
readStream.on('이벤트',(chunk)=>{
    콜백 함수
})
```

이벤트는 보통 data,end,error를 사용

이벤트 리스너를 붙이면 된다.

스트림의 크기의 기본값은 64KB 이므로 대부분의 txt 파일은 한번에 전송된다.

## **pipe**

스트림끼리 연결하는 것을 '파이핑한다'라고 표현함
```javascript
const fs = require('fs');
const readStream = fs.createReadStream('읽을 파일의 경로');
const writeStream = fs.createWriteStream('쓸 파일의 이름');
readStream.pipe(writeStream);
```
---
## 참조

node.js 교과서