#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) {
	bool swapped = false;
	int n = arr.size();
	for (size_t i = 0; i < n - 1 ; i++) {
		if (arr[i] > arr[i + 1]) {
			int temp;
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
			swapped = true;
		}	
	}
	n--; //reduces the range sorted after each pass
	if (swapped) {
		bubbleSort(arr);
	}
}
//function can't return an array, have to use vectors
std::vector<int> randArray(int size) {
	std::vector<int> randArr(size);
	for (int i = 0; i < size; i++) {
		randArr[i] = rand();
	}
	return randArr;
}