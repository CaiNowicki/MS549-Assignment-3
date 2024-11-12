#include <iostream>
#include "functions.h"
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;



int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random generator
    int size;
    cout << "How large should the array be?" << endl;
    cin >> size;
    std::vector<int> testArray = randArray(size); // randArray returns a vector

    //Check that array exists and is not sorted
    if (is_sorted(testArray.begin(), testArray.end())) {
        cout << "This array is already sorted!" << endl;
        return -1;
    }
    //Start the timer
    auto start = chrono::high_resolution_clock::now();
    // Sort the array
    bubbleSort(testArray);
    //Stop the timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    //test if array is sorted
    if (is_sorted(testArray.begin(), testArray.end())) {
        cout << "The array has been successfully sorted!" << endl;
    }

    cout << "bubbleSort took " << elapsed.count() << " seconds." << endl;
    return 0;
}

