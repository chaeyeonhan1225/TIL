# 📥 Vuex
## Vuex란?
Vuex는 Vue.js 애플리케이션에 대한 **상태 관리 패턴 + 라이브러리** 이다.<br>
애플리케이션의 모든 컴포넌트에 대한 **중앙 집중식 저장소 역할**을 하며 예측 가능한 방식으로 상태를 변경 할 수 있다.
```javascript
import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
  },
  mutations: {
  },
  actions: {
  },
  modules: {
  }
})

```

## 1. state
state를 사용하여 각 애플리케이션마다 하나의 저장소를 가질 수 있다.
```javascript
export default new Vuex.Store({
  state: {
    me: {
        name: 'Vue.js'
    }
  },
 ...
})
```
Vue 컴포넌트에서는 아래와 같은 방식으로 Vuex 상태를 가져올 수 있다.
```html
<div>{{ this.$store.state.me.name }}</div>
<div>{{ name }}</div>
...
<script>
export default {
    computed: {
        name() {
            return this.$store.state.me.name;
        }
    }
}
</script>
```
루트 인스턴스에 store 옵션을 제공함으로써 저장소는 루트의 모든 하위 컴포넌트에 주입되고, **this.$store**로 사용할 수 있다.
## 2.getters
Vuex를 사용하면 저장소에서 'getters'를 정의할 수 있다. getters는 저장소의 계산된 속성으로 생각할 수 있다.
```javascript
export default new Vuex.Store({
  state: {
    score: [ 80,90,50,100,30,40,60,70 ];
  },
  getters: {
    pass : state => {
        return state.score.filter(x => x>=70); 
    }
  }
 ...
})
```
모든 컴포넌트에서 아래와 같이 사용할 수 있다.
```javascript
export default {
    computed: {
        pass() {
            return this.$store.getters.pass;
        }
    }
}
```
## 3. mutations
vuex 저장소에서 실제로 상태를 변경하는 유일한 방법은 변이하는 것이다. Vuex 변이는 이벤트와 매우 유사하며, 각 변이에는 타입 문자열 핸들러가 있다.<br>
핸들러 함수는 실제 상태 수정을 하는 곳이며, 첫번째 전달인자로 상태를 받는다.
```javascript
export default new Vuex.Store({
  state: {
    count: 0
  },
  mutation: {
    increaseCount (state) {
        state.count++;
    }
  }
 ...
})
```
```javascript
this.$store.commit('increaseCount');
```
### 📬 페이로드를 가진 커밋
변이에 대해 payload라고 하는 store.commit에 추가 전달 인자를 사용할 수 있다.<br>
**store.js**
```javascript
  state: {
    Users: [],
    me: null,
  },
  ...
  mutations: {
    setnewUser: (state,payload)=>{
      state.Users.push(payload);
    },
  },
```
**⭐️ 변이는 무조건 동기적이어야 한다.**<br>
비동기성이 상태의 변이와 결합하면 프로그램을 파악하기 매우 어려워지므로 **액션**을 사용해 처리한다.

## 4. actions
- 상태를 변이시키는 대신 **액션으로 변이에 대한 커밋**을 한다.
- 작업에는 임의의 비동기 작업이 포함될 수 있다.

```javascript
 state: {
    Users: [],
    me: null,
  },
  mutations: {
    setnewUser: (state,payload)=>{
      state.Users.push(payload);
    },
  },
  actions: {
    signUp: (context, payload)=>{
      context.commit('setnewUser',payload);
    }
  },
```
commit을 여러 번 호출해야하는 경우 코드를 단순화하기 위해 전달인자 분해를 사용한다.
```javascript
signUp: ({ commit }, payload)=>{
      commit('setnewUser',payload);
}
```
액션은 컴포넌트내에서 <code>store.dispatch()</code> 메소드로 실행할 수 있다.
```javascript
onSubmitForm(){
      if(this.$refs.form.validate()){
        this.$store.dispatch('login',{
          email: this.email,
          password: this.password,
          nickname: this.nickname,
        });
      }
    }
```
액션 내에서도 다른 액션을 실행할 수 있다. 
```javascript
actions: {
    login: ({ commit },payload)=>{
      commit('setMe',payload);
    },
    signUp: ({ commit,dispatch }, payload)=>{
      commit('setnewUser',payload);
      dispatch('login',payload);
    }
  },
```
액션 내에서 **비동기** 작업을 수행할 수 있다.
```javascript
onSubmitForm(){
      if(this.$refs.form.validate()){
          this.$store.dispatch('signUp',{
                email: this.email,
                password: this.password,
                nickname: this.nickname,
              },
          })
          .then(() => {
            console.log('회원가입이 완료되었습니다.')
          })
          .catch((error) => {
            console.error(error);  
          })
      }
    }
```
<hr>

## 📁 Reference
[Vuex 공식 문서](https://vuex.vuejs.org/kr/)
