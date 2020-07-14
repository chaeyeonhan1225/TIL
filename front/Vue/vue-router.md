# Vue-Router 란? 💻
## 라우팅(Routing)
 웹 페이지간의 이동 방법, 현대 웹 앱 형태 중 하나인 싱글 페이지 애플리케이션(SPA, Single Page Application)에서 주로 사용하고 있다.

## 뷰 라우터
뷰 라우터는 **뷰에서 라우팅 기능을 구현할 수 있도록 지원하는 공식 라이브러리**이다.<br>

- 뷰 라우터를 구현할때 필요한 특수 태그와 기능


|태그|설명|
|:---:|:---:|
|\<router-link to="URL값">|페이지 이동 태그, 화면에서는 \<a>로 표시됨|
|\<router-view>|페이지 표시 태그|

## 라우트 값 설정하기
뷰 인스턴스를 생성하여 라우터를 삽입한다.
```html
<body>
...
  <router-view to="/main">Main 컴포넌트로 이동</router-view>
  <router-view to="/login">Login 컴포넌트로 이동</router-view>
...
</body>

<script>
import Main from './views/Main'
import Login from './views/Login'
import Router from 'vue-router'

// 각 url에 맞춰 표시할 컴포넌트 지정
var routes = [
  { path: '/main',component: Main },
  { path: '/login',component: Login }
];

// 뷰 라우터 정의
var router = new Router({
  routes
});     
</script>
```
**router.js**<br>
객체 형태로 라우터가 존재
```javascript
import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'

Vue.use(Router)

const About = () => {
  return  import(/* webpackChunkName: "about" */ './views/About.vue')
}

export default new Router({
  mode: 'history',
  base: process.env.BASE_URL,
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home // 연결되어 있는 컴포넌트 전부 다 로딩
    },
    {
      path: '/about',
      name: 'about-name',
      component: () => import(/* webpackChunkName: "about" */ './views/About.vue')// 해당하는 컴포넌트만 로딩
    }
  ]
})

```
- **lazy-loaded** : 해당하는 컴포넌트만 불러온다.
페이지를 빠르게 로딩할 수 있다.
```javascript
 component: () => import(/* webpackChunkName: "about" */ './views/About.vue')// 해당하는 컴포넌트만 로딩
```
##  📢 **라우터에 접근하는 방법**
### ✔️ **$router.push({ name: router-name })**

```html
<!--3가지 방법 다 사용 가능-->
<!--$router.push({ name: 'router-name' });-->
<!--$router.push({ path: 'router-path' });-->
<!--$router.push(path)-->
<v-list-tile router @click="$router.push({ name: 'home' })">
</v-list-tile>
```
객체 형태로 입력을 해주면 아래와 같이 query,param도 같이 넘길 수 있다.
```html
<v-list-tile router @click="$router.push({ name: 'home', query: {}, params: {})">
```
### ✔️ **\<router-link :to="{ name: router-name }">**
a 태그로 작동한다.
```html
<router-link :to="{ name: 'home' }">
  <h1>클릭</h1>
</rouetr-link>
```
### ✔️ Vuetify에서 지원해주는 기능
a 태그로 바뀐다.<br>
- exact 속성값: 정확하게 path값이 일치해야 한다.
```html
<v-list-tile router :to="{ name: 'home' }" exact>
```
<hr>

## 📁 Reference

[맨땅에 개발하기 유튜브]("https://youtu.be/aeczJLcr8xc")

Vue.js 입문 CAPTAIN PANGYO 장기효 지음