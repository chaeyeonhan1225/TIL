# ✍️ Vue Component간의 통신
컴포넌트란 조합하여 화면을 구성할 수 있는 블록을 말한다.<br>
각 컴포넌트들의 scope는 독립적으므로 다른 컴포넌트의 값을 직접적으로 참조할 수 없고 **props 속성이나 이벤트**를 발생시켜 각자의 상위 컴포넌트, 하위 컴포넌트의 값을 참조할 수 있다.
## 1. 상위 컴포넌트 -> 하위 컴포넌트 통신
상위 컴포넌트에서 하위 컴포넌트로 데이터를 전달할때는 **props속성**을 사용한다.
### **props**
상위 컴포넌트에서 하위 컴포넌트 태그에 v-bind 속성을 정의한다.
```html
<!--상위 컴포넌트-->
<body>
...
<childComponent v-bind:props속성명="상위 컴포넌트의 데이터"></childComponent>
...
</body>
```
하위 컴포넌트의 props 속성에 상위 컴포넌트가 하위 컴포넌트 태그에 넣은 props 속성명을 넣어준다.
```html
<!--하위 컴포넌트-->
<script>
export default {
    props: ['props속성명'],
    ...
}
</script>
```

아래는 적용한 예제이다.
```html
<!-- 상위 컴포넌트 -->
<body>
    ...
    <!--하위 컴포넌트인 LoginList 컴포넌트에 users란 값을 usersdata props 속성명으로 보낸다.-->
     <LoginList :usersdata="users"></LoginList>
    ...
</body>

<script>
import LoginList from "./components/LoginList"
export default {
    data() {
      return {
        users: [],
      }
    },
    components: {
      LoginList
    }
  }
</script>
```
상위 컴포넌트에서 users란 데이터를 보내줬으므로 하위 컴포넌트에서는 props 속성에 등록한 usersdata이름으로 사용이 가능하다.
```html
<body>
    ...
    <tr v-for="user in usersdata" :key="user.nick">
                <td>{{ user.nick }}</td>
                <td>{{ user.email }}</td>
    </tr>
    ...
</body>

<script>
export default {
    ....
    props: ['usersdata'],
    ...
}
</script>
```
## 2. 하위 컴포넌트 -> 상위 컴포넌트 통신
하위 컴포넌트에서 상위 컴포넌트로 데이터를 보내기 위해선 이벤트를 발생시켜야 한다.<br>
상위 컴포넌트에서 하위 컴포넌트의 특정 이벤트가 발생하기를 기다렸다가 **하위 컴포넌트에서 이벤트가 발생하면 상위 컴포넌트에서 이벤트를 수신**하는 방식이다.<br>
###  하위 컴포넌트
```javascript
this.$emit("이벤트 명",넘겨줄 변수);
```
SUBMIT 버튼을 누르면 login 함수가 실행되고 user 값이 this.$emit함수의 인자로 넘어간다.
```html
<!--하위 컴포넌트-->
<body>
  <v-btn v-on:click="login">SUBMIT</v-btn>
</body>
<script>
export default {
  data () {
    return {
      user: {},
    }
  },
  methods: {
    login() {
      this.$emit('login',user);
    }
  }
}
</script>
```
### 상위 컴포넌트
```html
<childComponent v-on:이벤트 명="이벤트 발생시 상위 컴포넌트에서 실행될 함수 이름"></childComponent>
```
하위 컴포넌트에서 login 함수가 실행되면 loginProcess 함수를 실행하고 인자로 넘어온 user값을 상위 컴포넌트로 받아온다.
```html
<body>
  ...
  <Login v-on:login="loginProcess"></Login>
  ...
</body>
<script>
export default {
   data() {
      return {
        users: [],
      }
    },
    methods: {
      loginProcess(user){
        this.users.push(user);
      }
    },
    components: {
      Login,
    }
}
</script>
```
## 3. 이벤트 버스
**서로 관련없는 독립적인 컴포넌트**끼리 통신할때 사용하는 방법이다. 이벤트 버스 역할을 할 뷰 인스턴스 하나를 생성해서 사용한다.
```javascript
// 이벤트 버스 생성
var EventBus = new Vue()

// 이벤트 발행
EventBus.$emit('message','hello word');

// 이벤트 구독
EventBus.$on('message',function(text){
  console.log(text);
});
```
먼저 전역으로 이벤트 버스를 만들어준 뒤, 각각의 컴포넌트에서 import해서 사용해주면 된다.
아래는 그 예제이다.
```javascript
import { eventBus } from "../main"

export default {
  data () {
    return {
      editedDate: null
    }
  },
  created () {
    eventBus.$on('userWasEdited', date => {
      this.editedDate = date
    })
  }
}
```
userWasEdited라는 이벤트 명으로 Date()를 보내주었다.
```html
<body>
  ...
  <v-btn @click="changeUser()">수정 완료</v-btn>
  ...
</body>
<script>
export default {
  ...
  methods: {
    changeUser () {
      eventBus.userWasEdited(new Date());
    }
  }
  ...
}
</script>
``` 
## 📁 Reference
[Vue.js한국 사용자 모임](https://vuejs-kr.github.io/jekyll/update/2017/02/13/vuejs-eventbus/)


[베이스캠프 티스토리 블로그](https://webruden.tistory.com/109)