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


