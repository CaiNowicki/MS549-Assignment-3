#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;

void bubbleSort(vector<int>& arr) {
	bool swapped;
	int n = arr.size();
	for (int i = 0; i < n - 1 ; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				// Swap elements
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
	}
	}
}

void merge(vector<int>& arr, int left, int mid, int right) {
	//Code from https://www.geeksforgeeks.org/merge-sort/
	int n1 = mid - left + 1;
	int n2 = right - mid;

	//temporary vectors
	vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	//merge temp vectors back into full array
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//Copy remaining elements of L[]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	//Copy remaining elements of R[]
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}
void mergeSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


//function can't return an array, have to use vectors
std::vector<int> randArray(int size) {
	std::vector<int> randArr(size);
	for (int i = 0; i < size; i++) {
		randArr[i] = rand();
	}
	return randArr;
}

