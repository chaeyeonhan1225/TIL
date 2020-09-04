# 자바의 참조타입
## 자바의 데이터 타입
자바의 데이터 타입은 크게 기본 타입과 참조 타입으로 분류된다.
- 기본 타입(primitive type): byte, char, short, int, long, float, double, boolean
- 참조 타입(reference type): 배열 타입, 열거 타입, 클래스, 인터페이스

기본 타입으로 선언한 변수는 실제 값을 변수 안에 저장한다.
```java
int a = 20;
boolean flag = false;
```
참조 타입으로 선언된 변수는 메모리의 주소를 값으로 갖는다.
주소를 통해 객체를 참조하므로 참조 타입으로 불리는 것이다.
```java
// str의 값은 객체의 주소 이다.
String str = "This is Reference Type";
```
## JVM이 사용하는 메모리 영역
- [기본기를 쌓는 정아마추어 코딩블로그 - JVM 구조와 자바 런타임 메모리구조](https://jeong-pro.tistory.com/148) 
이글을 많이많이 참조 하였다.

``java.exe``로 JVM이 시작되면 JVM은 운영체제에서 할당받은 메모리 영역(Runtime Data Area) 을 아래와 같이 세부 영역으로 구분해서 사용한다.
![](https://images.velog.io/images/gkscodus11/post/c549f73c-f370-48d4-887f-fca99e4f6516/image.png)
**1. 메소드 영역(Method Area)**
메소드 영역에서는 코드에서 사용되는 클래스들을 클래스 로더로 읽어 클래스별로 런타입 상수풀(runtime constant pool), 필드(field) 데이터, 메소드(method) 데이터(메소드 이름,리턴 타입, 파라미터, 접근 제어자), 메소드 코드, 생성자(constructor), static 변수, final class 변수 등이 생성되는 영역이고 모든 스레드가 공유하는 영역이다.
> ### 스레드(Thread)란?
하나의 프로세스 내에서 실행되는 작업단위!!

**2. 힙(Heap) 영역**
힙 영역은 객체와 배열이 생성되는 영역이다. 힙 영역에 생성된 객체와 배열은 JVM 스택 영역의 변수나 다른 객체의 필드에서 참조한다. 만약 참조하는 변수나 필드가 없다면 JVM은 쓰레기 수집기(Garbage Collector)를 실행시켜 힙 영역에서 자동으로 제거한다.
**3. 스택(Stack) 영역**
지역 변수, 파라미터, 리턴 값, 연산에 사용되는 임시 값등이 생성되는 영역이다. 메소드를 호출할때마다 스택 영역이 생성된다. 기본 타입 변수와 참조 타입 변수가 push 되거나 pop 된다. 변수는 선언된 블록 안에서만 스택에 존재하고 블록을 벗어나면 스택에서 사라진다.
아래와 같은 코드에서 if문을 빠져나가면 c는 사라지고, 객체 Person은 힙 영역에 생성되며, 스택 영역에서 p1은 힙 영역에서 생성된 객체의 주소 값을 가진다.
```java
int a = 1;
boolean b = true;
if(b) {
	char c = 'B';
}
Person p1 = new Person();
```
![](https://images.velog.io/images/gkscodus11/post/e44f04a5-7c60-4ae6-af95-2a15dd97aa84/image.png)

**4. PC Register 영역**
스레드가 생성될때마다 생성되는 영역으로 현재 스레드가 실행되고 있는 부분의 주소와 명령을 저장하고 있는 영역이다.
**5. Native Method Stack**
자바 외 언어로 작성된 네이티브 코드를 위한 메모리 영역이다.

## 자바의 참조타입
### 참조타입의 값은 주소
자바에서 참조타입은 배열, 열거, 문자열, 클래스, 인터페이스 등이 있다.
아래의 코드에서 s1과 s2는 name이 "Jane"이고 age가 16인 Student 객체이고 서로 값이 같아서 s1과 s2는 같은 값으로 보이지만, 서로 참조하고 있는 객체(힙 영역에 생성된 객체)가 다르므로 주소가 다르다. s1 == s2를 했을때 false가 나온다. 
![](https://images.velog.io/images/gkscodus11/post/2283a0d5-43f9-4184-aadc-8f335b0cfe32/image.png)
```java
Student s1 = new Student("Jane",16);
Student s2 = new Student("Jane",16);
System.out.println(s1 == s2);	// false
```
### String
String은 문자열 리터럴이 동일하면 String 객체를 공유하도록 되어있어서 아래와 같은 경우는
s1 == s2는 true이다.
```java
String s1 = "Hello, World!";
String s2 = "Hello, World!";
System.out.println(s1 == s2);	// true
```
객체 생성 연산자``new``를 사용하여 힙 영역에 String 객체를 생성했을 경우에는 s1과 s2는 서로 다른 String 객체를 참조한다.
```java
String s1 = new String("Hello, World!");
String s2 = new String("Hello, World!");
System.out.println(s1 == s2);	// false
```
따라서 문자열만을 비교할 때에는 ``equals()``메소드를 사용한다.
```java
String s1 = "Hello, World!";
String s2 = "Hello, World!";
String s3 = new String("Hello, World!");
System.out.println(s2 == s3);	// false
System.out.println(s2.equals(s3));	// true
```
### Array
배열은 **같은 타입**의 데이터를 **연속**으로 나열시킨 자료구조이다.
자바에서 배열은 참조 타입으로 아래와 같이 선언한다.
```java
int[] arr1;
double arr2[];
char[] arr3 = { 'a','b','c' };
```
중괄호를 사용한 배열 생성은 선언할때만 가능하다. 배열 변수를 미리 선언하고, 나중에 값을 넣는 상황이라면 ``new``연산자를 사용하면 된다.
```java
int[] arr1 = {1,2,3};
System.out.println(arr1[0]);
int arr2[] = null;
arr2 = new int[5];	// 길이가 5인 배열 생성
for(int i=0;i<5;++i) {
	arr2[i] = i+1;
}
```
다차원 배열은 아래와 같이 생성하면된다.
```java
int arr3[][] = new int[2][3];	// 행이 2, 열이 3인 다차원 배열
```
객체를 참조하는 배열도 만들 수 있다.
```java
String[] strArr = new String[3];
strArr[0] = "Hello";
strArr[1] = "Eclipse";
strArr[2] = "Java";
```
---
### 참고
- [이것이 자바다-신용권의 Java 프로그래밍 정복(1)](https://www.hanbit.co.kr/store/books/look.php?p_code=B1460673937)
- [기본기를 쌓는 정아마추어 코딩블로그 - JVM 구조와 자바 런타임 메모리구조](https://jeong-pro.tistory.com/148) 



