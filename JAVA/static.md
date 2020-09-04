# static
## static
static은 '고정된'이란 의미를 가지고 있다. 자바에서 정적 멤버란 클래스에 고정된 멤버로서 객체를 생성하지 않고 사용할 수 있는 필드와 메소드를 말한다.
**정적 멤버는 객체(인스턴스)에 소속된 멤버가 아니라 클래스에 소속된 멤버**이다.
## 정적 멤버와 정적 메소드
Calculator 클래스가 있다.
```java
public class Calculator {
	int num = 0;
	Calculator(int n){
		num = n;
	}
	static double pi = 3.14;	// 정적 멤버
	static int sum(int a,int b) {	// 정적 메소드
		return a+b;
	}
}
```
- 여기서 num는 인스턴스 멤버로서 특정한 인스턴스마다 별도로 존재한다. num은 Calculator마다 다를 수 있기 때문이다. 
반면, pi는 변하지 않는 공용적인 데이터이므로 정적 멤버로 선언하는 것이 좋다.

- 정수 2개의 합을 구하는 sum 함수는 외부의 매개값을 가지고 덧셈을 수행하므로 정적 메소드로 선언하는 것이 좋다.

**정적 멤버와 메소드는 클래스당 하나씩 생성되어 모든 객체에서 공통으로 참조하는 변수이다.(객체의 변수가 아니다!)**

## 💬 어떻게 사용할까?
정적 멤버는 클래스가 메모리로 로딩되면 바로 사용가능하다. 
클래스 이름으로 접근할 수 있다.
```java
double a =  3 * 3 * Calculator.pi;
int sum = Calculator.sum(1,2);
```
객체 참조 변수로도 접근이 가능하지만 이클립스에서 정적 멤버나 메소드를 클래스 이름으로 접근하지않고 객체 참조 변수로 접근했을 경우, 경고 표시를 낸다.
```java
Calculator cal = new Calculator(1);
System.out.println(cal.pi);	
// The static field Calculator.pi should be accessed in a static way
```
### 정적 초기화 블록
정적 필드는 선언과 동시에 초기값을 주는 것이 보통이지만 계산이 필요한 초기화 작업이 필요할 경우,  인스턴스 필드는 인스턴스를 생성할때 생성자에서 초기화할 수 있지만, 정적 필드는 객체 생성 없이도 사용해야 하므로 생성자에서 초기화할 수 없다. 
따라서 정적 필드의 복잡한 초기화 작업은 ``static block(정적 블록)``을 사용한다.

정적 블록은 클래스가 메모리로 로딩될 때 자동으로 실행되며, 클래스 내부에 여러개가 선언되어도 상관없고 클래스가 메모리로 로딩될 때 선언된 순서대로 실행된다.
```java
public class Computer {
	static String month = "7";
	static String day = "29";
	static String purchasedate;
	static {
		purchasedate = month + "/" + day;
	}
}
```
### 주의할 점
정적 메소드와 정적 멤버는 객체가 없어도 실행되야 하므로, 이들 내부에 인스턴스 필드와 인스턴스 메소드를 사용할 수 없다. ``this``키워드 역시 사용할 수 없다.
아래는 그 예제이다.
```java
public class Main {

	int cnt = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(cnt);
	}

}
```
``main()``메소드도 정적 메소드이므로 객체 생성 없이 인스턴스 필드와 인스턴스 메소드를 ``main()``메소드내에서 바로 사용할 수 없다. 따라서 위의 코드는 Cannot make a static reference to the non-static field cnt 이런 에러가 뜬다.
아래와 같이 수정하면 정상적으로 작동한다.
```java
public class Main {

	int cnt = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Main m = new Main();
		System.out.println(m.cnt);
	}

}
```
## ✏️ static 멤버와 메소드는 어느 경우에 사용할까?
**1. 메모리 효율**
자주 변하지 않는 공용된 데이터에 대한 접근에 있어서 매번 생성하는 것보다는 static 멤버로 선언하는것이 메모리 효율을 높일 수 있다.
**2. 변수 공유**
User라는 클래스가 있고 인스턴스가 생성될때마다 생성된 유저의 총 인원을 알고싶을때 static 변수를 유용하게 사용할 수 있다. 전역변수처럼 사용하는 것이다.
```java
public class User {
	static int totalUser = 0;
	String id;
	String password;
	String nickname;
	User(String id,String password,String nickname){
		this.id = id;
		this.password = password;
		this.nickname = nickname;
		totalUser++;
	}
}
```
```java
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		User user1 = new User("user1","1234","Java");
		User user2 = new User("user2","1234","C++");
		System.out.println(User.totalUser);	// 2
	}

}
```
**3.유틸리티 메소드**
유틸리티 관련 함수들은 static 메소드를 사용하는것이 좋다.
대표적인 util class는 ``java.util.Math``가 있다.

---
### 참고
- [이것이 자바다-신용권의 Java 프로그래밍 정복(1)]("https://www.hanbit.co.kr/store/books/look.php?p_code=B1460673937")
- [점프 투 자바 07-3 정적 변수와 메소드]("https://wikidocs.net/228")
