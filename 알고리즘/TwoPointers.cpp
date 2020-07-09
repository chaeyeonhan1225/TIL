#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// 수열의 길이 N, 부분 연속 수열의 합 M
	int N, M;
	
	cin >> N >> M;

	vector<int> s;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	
	// 투 포인터 알고리즘
	int end = 0;
	int sum = 0;
	int ans = 0;
	for (int start = 0; start < N; ++start) {
		while (sum < M && end < N) {	// sum 이 M보다 작으면 end를 가능한 한 뒤로 이동
			sum += s[end];
			end++;
		}
		// sum은 while문을 빠져나와 sum >= M 인 상태
		if (sum == M) ans++;	// sum == M 이면 카운트
		sum -= s[start];		// start를 다음 칸으로 이동하고 sum에 s[start]를 빼준다.
	}
	
	cout << ans << "\n";

	return 0;
}