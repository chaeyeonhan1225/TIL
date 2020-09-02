# URL
url이란 Uniform Resorce Locators의 약자로 **서버에 자원을 요청하기 위해** 입력하는 영문 주소이다.

## url의 구조
``protocol://web server/resorce path?query``

### 1. protocol
프로토콜이란 컴퓨터간에 정보를 주고받을 때의 규약을 뜻한다.
```http://```

http는 인터넷에서 데이터를 교환하기 위하여 사용되는 프로토콜이다. TCP/IP 통신 위에서 동작하며 포트는 80번을 사용한다.
### 2. web server
어떤 웹 서버가 요구되는 것인지 가리킨다. 도메인 이름이나 IP 주소가 들어간다.(IP 주소를 직접입력하는건 잘 사용되지 않는다.)
```http://localhost:80```

도메인주소(혹은 IP 주소):포트번호 를 사용해서 웹 서버에 접근할 수 있다. 하지만 기본 http(80)나 https(443)포트를 사용한다면 생략해서 사용한다.

### 3. resorce path
```http://localhost/profile/following.html```
``profile/following.html``은 웹 서버에서 자원에 대한 경로이다. 보여주고자 하는 파일이 있는 경로를 뜻한다. 요즘에는, 실제 물리적 경로를 나타내지 않고, 웹 서버에서 추상화해서 보여준다.
### 4. query
```http://localhost/user?name=value1&key=value2```
``?name=value1&key=value2``는 웹 서버에 제공하는 파라미터이다. 파라미터들은 & 기호로 구분하고 resorce path와 query는 ?로 구분한다.
서버에서 응답을 하기 전에 추가적인 작업을 위해 이 파라미터들을 사용할 수 있다.

---
## Reference
- [프런트엔드 개발자가 알아야하는 HTTP 프로토콜 Part 1 - CAPTAIN PANGYO](https://joshua1988.github.io/web-development/http-part1/)
- [MDN web docs](https://developer.mozilla.org/ko/docs/Learn/Common_questions/What_is_a_URL)