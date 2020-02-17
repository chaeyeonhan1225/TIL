#include <iostream>

using namespace std;

void merge(int a[], int left, int mid, int right)
{
	int i = left;	// 병합할 부분의 왼쪽의 첫번째 인덱스
	int j = mid + 1;	// 병합할 부분의 오른쪽의 첫번째 인덱스 
	int *temp = new int[right-left + 1];	// 임시배열 생성 
	int k = 0;

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}

	if (i > mid) {
		while (j <= right) {
			temp[k++] = a[j++];
		}
	}
	else {
		while (i <= mid) {
			temp[k++] = a[i++];
		}
	}

	k = 0;
	for (int h = left; h <= right; ++h) {
		cout << temp[k] << " ";
		a[h] = temp[k++];
	}
	cout << endl;

	delete[] temp;
}

void mergesort(int a[], int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int main(void)
{
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	mergesort(a, 0, n - 1);
	
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	

	delete[] a;
	system("pause");
	return 0;
}