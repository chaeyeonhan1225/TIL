#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> s(N+1);	
	vector<int> prefix_sum(N+1,0);	

	s[0] = 0;
	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		s[i] = a;
	}
	
	// prefix_sum을 구한다. 
	for (int i = 1; i <= N; ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + s[i];
	}

	// L과 R사이의 구간합은 prefix_sum[R] - prefix_sum[L - 1] 이다.
	for (int i = 0; i < M; ++i) {
		int L, R;
		cin >> L >> R;
		cout << prefix_sum[R] - prefix_sum[L - 1] << "\n";
	}

	return 0;
}