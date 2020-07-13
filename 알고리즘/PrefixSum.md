# 🗂 구간 합 구하기(Prefix Sum)
## 해결해야 할 문제
수열 A가 있을때 L과 R사이의 원소의 합을 구하시오. 쿼리는 M번 주어진다.<br>

**수열 A**
|index|1|2|3|4|5|6|7|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|value|10|3|24|33|5|25|4|
### 1. **N^2 방법**
```c
for(int i=0;i< M;++i){
    int L,R;
    cin >> L >> R;
    int sum = 0;
    for(int i=L;i<=R;++i) {
        sum += a[i];
    }
    cout << sum << "\n";
}
```
A의 원소 개수는 N이고 쿼리가 M개 있다면, 시간복잡도는  **O(NM)** 이다.

### 2. **선형 시간으로 해결하는 방법**

미리 구간합(Prefix Sum)을 구하면 M개의 쿼리 마다 O(1)로 해결 할 수있다.
### ✔️ 구간합 구하기
```c++
int prefix_sum[MAX];

// prefix_sum 배열을 0으로 초기화
fill(prefix_sum,prefix_sum+N,0);

for(int i=1;i<N;++i){
    prefix_sum[i] = prefix_sum[i-1] + a[i];
}

for(int i=0;i<M;++i){
    int L,R;
    cin >> L >> R;
    cout << prefix_sum[R] - prefix_sum[L-1] << "\n";
}
```
**prefix_sum**
|index|0|1|2|3|4|5|6|7|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|value|0|10|13|37|70|75|100|104|

만약 L = 2, R = 5 라면, sum은 a[R] - a[L-1] = a[5] - a[1] = 65 <br>
L = 1, R = 6 a[6] - a[0] = 100 <br>
L = 3, R = 5 a[5] - a[2] = 63 이다. <br>  

구간 합을 구하는 데는 O(N)이 들고, M개의 쿼리마다 1번의 연산을 수행하므로 시간 복잡도는 **O(N+M)** 이다.

## 🗃정리

1. 쿼리마다 N번의 연산을 수행하는 방식은 **O(NM)**

2. Prefix Sum 을 이용하면 **O(N+M)** 에 문제해결 가능

<hr>

## 📁 Reference
[안경잡이 개발자 유튜브]("https://youtu.be/rI8NRQsAS_s")