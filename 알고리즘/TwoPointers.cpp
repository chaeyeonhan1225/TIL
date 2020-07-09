#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// ������ ���� N, �κ� ���� ������ �� M
	int N, M;
	
	cin >> N >> M;

	vector<int> s;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	
	// �� ������ �˰���
	int end = 0;
	int sum = 0;
	int ans = 0;
	for (int start = 0; start < N; ++start) {
		while (sum < M && end < N) {	// sum �� M���� ������ end�� ������ �� �ڷ� �̵�
			sum += s[end];
			end++;
		}
		// sum�� while���� �������� sum >= M �� ����
		if (sum == M) ans++;	// sum == M �̸� ī��Ʈ
		sum -= s[start];		// start�� ���� ĭ���� �̵��ϰ� sum�� s[start]�� ���ش�.
	}
	
	cout << ans << "\n";

	return 0;
}