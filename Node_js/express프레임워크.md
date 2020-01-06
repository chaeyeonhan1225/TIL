# **Express 프레임 워크**

> Express-generator

프레임워크에 필요한 package.json 을 만들어주고 기본 폴더 구조까지 잡아주는 패키지

express-generator는 콘솔 명령어이므로 npm 전역 설치가 필요

<pre><code>express "프로젝트 이름" --view=pug</code></pre>

폴더에 들어가서 npm 모듈들을 설치하면 된다.

<pre><code>cd "폴더 이름" && npm i</code></pre>

- **app.js**: 핵심적인 서버 역할
- **www**: 서버를 실행하는 스크립트
- **public**: 외부(브라우저 등의 클라이언트)에서 접근 가능한 파일들을 모아둔 곳
- **routes**: 주소별 라우터를 모아둠
- **view**: 템플릿 파일을 모아둔 곳

## **Reference**

Node.js 교과서 