#pragma once
#include <vector> 

void bubbleSort(std::vector<int>& arr); 
void mergeSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);

std::vector<int> randArray(int size);    // randArray should return a vector of ints
