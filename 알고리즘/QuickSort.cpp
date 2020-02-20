#include <iostream>

using namespace std;

const int n = 10;	// 배열의 크기

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i = left;
	int j = right + 1;
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	if (left < right) {
		while (i <= j) {
			do
				i++;
			while (arr[i] < pivot);
			do
				j--;
			while (arr[j] > pivot);
			if (i < j) {
				swap(arr[i], arr[j]);
			}
			else
				break;
		}
	
		swap(arr[j], arr[left]);

		quicksort(arr, left, j - 1);
		quicksort(arr, j + 1, right);
	}
}

int main(void)
{
	int arr[n] = { 5, 3, 1, 10, 9 ,4, 8 , 7, 2, 6 };
	
	quicksort(arr, 0, 9);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}