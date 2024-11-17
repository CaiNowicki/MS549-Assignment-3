#include <iostream>
#include <fstream> //for file write function
#include "functions.h"
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;



int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random generator
    ofstream outfile("sort_data.csv", ios::app);  //opens file in append mode
    while (true) {
        int size;
        cout << "How large should the array be? " << endl;
        cout << "Or enter 0 to quit." << endl;
        cin >> size;
        if (size == 0) {//Exit conditions
            cout << "Program complete." << endl;
            break;
        }
        std::vector<int> testArray = randArray(size); // randArray returns a vector

        //Check that array exists and is not sorted
        if (is_sorted(testArray.begin(), testArray.end())) {
            cout << "This array is already sorted!" << endl;
            return -1;
        }
        vector<int> testArrayCopy = testArray;
        vector<int> testArrayCopy2 = testArray;
        //Start the timer - built-in sort
        auto startBI = chrono::high_resolution_clock::now();
        //Sort the array
        sort(testArray.begin(), testArray.end());
        // Stop the timer 
        auto endBI = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsedBuiltin = endBI - startBI;

        //Start the timer - bubble sort
        //auto startBS = chrono::high_resolution_clock::now();
        // Sort the array
        //bubbleSort(testArrayCopy);
        //Stop the timer
        //auto endBS = chrono::high_resolution_clock::now();
        //chrono::duration<double> elapsedBubble = endBS - startBS;

        
        //Start the timer - merge sort
        auto startMS = chrono::high_resolution_clock::now();
        // Sort the array
        mergeSort(testArrayCopy2, 0, size - 1);
        //Stop the timer
        auto endMS = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsedMerge = endMS - startMS;
        
        //test if array is sorted
        if (is_sorted(testArray.begin(), testArray.end())) {
            cout << "The array has been successfully sorted!" << endl;
        }
        else {
            cout << "Error: Array failed to sort.";
            return -1;
        }
        //Results displayed on screen
        cout << "For an array of length " << size << ":" << endl;
        cout << "Built in sort took " << elapsedBuiltin.count() << " seconds." << endl;
        //cout << "Bubble Sort took " << elapsedBubble.count() << " seconds." << endl;
        cout << "Merge Sort took " << elapsedMerge.count() << " seconds." << endl;
        //Writing the results to a CSV file
        outfile << size << "," << elapsedBuiltin.count() << "," << elapsedMerge.count() << endl;

    }
    outfile.close();
    return 0;
}

