#include <iostream>

using namespace std;

int main(void)
{
	int a[10] = { 2, 17, 19, 21, 45, 50, 55, 72, 80, 120 };
	int key;
	cin >> key;

	int left = 0;
	int right = 9;
	bool flag = false;
	while (left <= right) {
		cout << "left: " << left << ",right: " << right << endl;
		int pivot = (left + right) / 2;
		if (a[pivot] == key) {
			flag = true;
			cout << pivot <<  endl;
			break;
		}
		else if (a[pivot] < key) {
			left = pivot + 1;
		}
		else {
			right = pivot - 1;
		}
	}

	if (!flag) {
		cout << "검색 실패" << endl;
	}
	
	return 0;
}