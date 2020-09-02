# 🍭 Vue computed

## 1. computed 속성
```html
    <div>{{ message.split('').reverse().join('')}}</div>
```
위와 같은 코드는 아래 코드의 computed 속성을 통해 아래와 같이 수정할 수 있다.
```html
<template>
  <div>
    <p>원본 메시지: "{{ message }}"</p>
    <p>역순으로 표시한 메시지: "{{ reversedMessage }}"</p>
  </div>
</template>

<script>
export default {
  name: 'test',
  data(){
    return {
      message: '안녕하세요'
    }
  },
  computed: {
    reversedMessage: function () {
      return this.message.split('').reverse().join('')
    }
  }
}
</script>
```
### ✏️ computed속성 vs method속성
computed 속성은 method 속성으로도 구현 가능하다.
```html
<p>뒤집힌 메시지: "{{ reversedMessage() }}"</p>
```
```javascript
methods: {
  reversedMessage: function () {
    return this.message.split('').reverse().join('')
  }
}
```
computed 속성은
1. 템플릿 내에서 ( )를 붙이지 않는다.
2. computed속성은 **종속 대상을 따라 저장(캐싱)** 된다.
3. 해당 속성의 **종속된 대상이 변경될때만 함수를 실행**한다.
4. return 값이 반드시 있어야한다.

위의 예제의 경우 computed 속성은 message 값이 변경될때마다 실행되는 것이다.<br>
이에 비해 **method 속성은 렌더링 될때마다 함수를 실행**한다. 캐싱을 원하지 않는 경우나 파라미터를 받아야 할 때는 method 속성을 사용하면 된다.

<hr>

## 📁 Reference
[Vue.js 공식 문서](https://kr.vuejs.org/v2/guide/computed.html)