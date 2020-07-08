# ✔️ 디렉티브
디렉티브는 v- 접두사를 가지는 특수 속성이다. 디렉티브는 표현식의 값이 변경될 때 사이드 이펙트를 반응적으로 DOM에 적용하는 역할을 한다.
### 1. **v-bind**<br>
v-bind는 엘리먼트의 속성을 동적으로 설정해준다.
```html
<body>
    <div v-bind:id="idA"></div>
</body>
<script>
  var app = new Vue({
  el: '#app', 
  data: {
    name: 'Hello',
    idA: 'user'
  }   
});
</script>
```
위와 같이 v-bind 속성으로 지정할 HTML 속성(id,class,style,...)이나 props속성 앞에 접두사로 붙여준다.
그 결과는 아래와 같다.
```html
<div id="user"></div>
```
v-bind문법을 :로 간소화 할 수도 있다.
```html
<body>
    <div :id="idA"></div>
</body>
<script>
  var app = new Vue({
  el: '#app', 
  data: {
    name: 'Hello',
    idA: 'user'
  }   
});
</script>
```
### 2. **v-if**
지정한 뷰 데이터 값의 참, 거짓 여부에 따라 해당 HTML 태그를 화면에 표시하거나, 표시하지 않는다.
```html
<body>
  <div id="app">
    <h1>{{ name }}</h1>
    <div :id="idA"></div>
    <div v-if="flag">참 입니다.</div>
    <!--this.flag가 true이면 표시 아니면 표시x-->
  </div>
  
  <script src="https://unpkg.com/vue/dist/vue.js"></script>
</body>
</html>

<script>
  var app = new Vue({
  el: '#app', 
  data: {
    name: 'Hello',
    idA: 'user',
    flag: 'true'
  }   
});
</script>
```
### 3. **v-on**
화면 요소의 이벤트를 감지하여 처리할때 사용한다.
```html
<button v-on:click="clickBtn">클릭</button>
...
<script>
  var app = new Vue({
  el: '#app', 
  data: {
    name: 'Hello',
    idA: 'user',
    flag: 'true'
  } ,
  methods: {
    clickBtn() {    // 버튼 클릭시 이벤트 실행
      this.flag = false;
    }
  }
  });
</script>
```
v-on 디렉티브로 메서드를 호출할 때 인자값을 넘길 수도 있다.
```html
<button v-on:click="clickBtn(10)">클릭</button>
...
<script>
  var app = new Vue({
  el: '#app', 
  data: {
    name: 'Hello',
    idA: 'user',
    flag: 'true'
  } ,
  methods: {
    clickBtn(num) {    // 버튼 클릭시 이벤트 실행
      alert(num);
    }
  }
  });
</script>
```
### 4. **v-model**
폼(form)에서 주로 사용되는 속성으로 폼에 입력한 값을 뷰 인스턴스의 데이터와 즉시 동기화 한다.
input,select,textarea 태그에만 사용할 수 있다.
```html
...
<input type="text" v-model="inputText">
<div>{{ inputText }}</div>
<!--내용을 입력할때 마다 inputText와 동기화 된다.-->
<button v-on:click="clickBtn">클릭</button>
...
<script>
  var app = new Vue({
  el: '#app', 
  data: {
    inputText: null
  } ,
  methods: {
    clickBtn() {
      alert(this.inputText);
    }
  }
});
</script>
```
### 5. **v-for**
지정한 뷰 데이터의 개수만큼 해당 HTML 태그를 반복 출력한다.
```html
...
<li v-for="fruit in fruits">{{ fruit }}</li>
<!--
- apple
- banana
- orange
    -->
...
<script>
    ...
    data () {
        return {
             fruits: ['apple','banana','orange']
        }
    }
    ...
</script>
```
<hr>

## 📁 Reference
1. [VELOPERT.LOG 블로그]("https://velopert.com/3095")
2. Vue.js 입문 (장기효 지음, 이지스 퍼블리싱)
3. [Vue.js 공식문서]("https://kr.vuejs.org/v2/guide/")

