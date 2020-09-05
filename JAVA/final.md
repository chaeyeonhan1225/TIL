# final
## final
final 필드는 초기값이 저장되면 프로그램 실행 도중에 수정할 수 없다.
```java
final String str = "Final!!";
```
### final 필드의 초기값
final 필드에 초기값을 줄 수있는 방법은 두 가지가 있다.

1. 선언 시에 초기값을 준다.
```java
final int num = 1;
```
2. 생성자에서 초기값을 준다.
```java
// Student 클래스
public Class Student{
	final String name;
	final int grade;
    Student(String name,int grade){
    	this.name = name;
        this.grade = grade;
    }
}
...
// main 함수
public static void main(String args[]){
	Student s1 = new Student("Han",15);
}
```
## 상수(constant)
상수란 변하지 않는 불변의 값을 말한다. 상수는 객체마다 다를 필요도 없고 저장할 필요도 없다.
자바에서는 상수가 ``static``이면서 ``final``이어야한다.
```java
static final double PI = 3.141592;
```
상수이름은 대문자로 작성하는 것이 관례이고, 선언 시에 초기값을 줘야한다. (static block에서 초기화도 가능)

---
### 참고
- [이것이 자바다-신용권의 Java 프로그래밍 정복(1)]("https://www.hanbit.co.kr/store/books/look.php?p_code=B1460673937")

