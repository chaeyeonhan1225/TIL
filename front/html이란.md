# HTML
 HTML(HyperText Markup Language)은 말 그래도 하이퍼텍스트를 마크업하는 언어이다.
#### 하이퍼 텍스트, 마크업 이란?
 - 하이퍼 텍스트: 웹 사이트에서 링크를 클릭해 다른 문서나 사이트로 즉시 이동할 수 있는 기능
 - 마크업: 태그(tag)를 사용해 문서에서 어느 부분이 제목이고,본문인지,어느 부분이 사진이고 링크인지 표시하는 것
 ---
 ### 태그
 태그는 소문자를 사용하며, 여는 태그와 닫는 태그를 정확히 입력해야한다. (\<img>태그나 \<br> 태그처럼 닫는 태그가 없는 경우도 있다.)<br>
 아래와 같이 속성과 함께 사용할 수 있다.
 ```html
 <태그 속성="속성 값",속성 = "속성 값"></태그>
 ```
 ---
 ## HTML 문서의 기본 구조

1. **\<!DOCTYPE html>**<br>
  현재 문서가 HTML5 언어로 작성된 웹 문서라는 뜻이다.
 ```html
<!DOCTYPE html>
 ```
2. **\<html>\</html>**<br>
웹 문서의 시작과 끝을 나타내는 태그
```html
<html lang="ko">
```
- lang이라는 속성을 사용해 문서에 사용할 언어를 지정할 수 있다.


|코드|de|en|fr|ja|ko|zh|
|--|:--:|:--:|:--:|:--:|:--:|:--:|
||독일어|영어|프랑스어|일본어|한국어|중국어|


3. **\<head>\</head>**<br>
브라우저에게 정보를 주는 태그
```html
<head>
    <title>문서 제목</title>
    // 문자 세트 지정 (인코딩 방법)
    <meta charset="UTF-8">
    // 모바일 기기 고려
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    // 인터넷 익스플로러 브라우저 고려
    <meta http-equiv="X-UA-Compatible" content="ie=edge">

</head>
```
4. **\<body>\</body>**<br>
실제 브라우저에 표시될 내용
``` html
<body>
    <h1>Hello World!</h1>
</body>
```



