# 💬 HTTP 상태 코드
HTTP 상태 코드는 특정 HTTP 요청이 성공적으로 완료되었는지 알려준다.
## 📣 성공 응답
|코드|의미|
|--|:--|
|**200**|요청이 성공적으로 됨 (OK)|
|201|요청이 성공적으로 되었으며, 그 결과 새로운 리소스가 생성됨 (Created)|
|204|요청이 성공적으로 되었지만, 제공할 내용이 없음 (No Content)|
## 📣 리다이렉트 응답
|코드|의미|
|--|:--|
|300|요청에 대해서 하나 이상의 응답이 가능함 (Multiple Choice)|
|301|요청한 리소스의 url가 변경되었음 (Moved Permanently)|
|302|요청한 리소스의 url이 일시적으로 변경되었음 (Found)|

## 📣 실패 응답   
### 클라이언트 에러 응답
|코드|의미|
|--|:--|
|400|잘못된 문법으로 인하여 서버가 요청을 이해할 수 없음 (Bad Request)|
|401|클라이언트가 미인증 상태임 (Unauthorized)|
|403|클라이언트는 콘텐츠에 접근할 권리가 없음 (Forbidden)|
|**404**|서버에서 요청받은 url을 찾을 수 없음 (잘못된 url로 접근) (Not Found)|

### 서버 에러 응답
|코드|의미|
|--|:--|
|**500**|서버에 오류가 발생(Internal Server Error)|
|501|요청 방법이 서버에서 지원하지 않는 방법이여서 처리할 수 없음 (Not Implemented)|
|503|서버가 유지보수등의 이유로 인해 요청을 처리할 수 없음 (Service Unavailable)|
|504|서버가 게이트웨이 역할을 하고 있으며 적시에 응답을 받을 수 없음 (GateWary Timeout)|
|505|요청에 사용된 HTTP 버전은 서버에서 지원되지 않음 (HTTP Version Not Supported)|
<hr>

## 📁 Reference
[MDN Web 공식문서]("https://developer.mozilla.org/ko/docs/Web/HTTP/Status") 


