/*
 Trang Hoang
 CS110B
 Dave Harden
 12/3/20
 a14_3.cpp
 
 Assignment 14.3
 
 Write a recursive function to sort an array of integers into ascending order using the
 following idea: the function must place the smallest element in the first position, then
 sort the rest of the array by a recursive call. This is a recursive version of the
 selection sort. (Note: You will probably want to call an auxiliary function that finds the
 index of the smallest item in the array. Make sure that the sorting function itself is
 recursive. Any auxiliary function that you use may be either recursive or iterative.)
 Embed your sort function in a driver program to test it. Turn in the entire program and
 the output.
 
 Created by nyccowgirl on 12/3/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;

int smallestIndex(const int array[], int left, int right);
void sortInt(int array[], int idx, int size);

int main(int argc, const char * argv[]) {
    int nums1[] = {9, 8, 3, 4, 5, 7, 2, 6};
//    int nums2[] = {1};
     
    sortInt(nums1, 0, sizeof(nums1)/sizeof(nums1[0]));
    
    for (int num : nums1) {
        cout << num << ' ';
    }
    
    cout << endl;
    
    return 0;
}






int smallestIndex(const int array[], int left, int right) {
    int smallIdx;
        
    // base case
    if (left == right) {
        return left;
    }
    
    // smallest index of remaining array
    smallIdx = smallestIndex(array, left + 1, right);
    
    return (array[left] < array[smallIdx])? left : smallIdx;
}






void sortInt(int array[], int idx, int size) {
    int smallIdx;
    
    // base case is to do nothing if array size is 1
    if ((idx < (size - 1))) {
        smallIdx = smallestIndex(array, idx, size - 1);
        
        if (smallIdx != idx) {
            swap(array[smallIdx], array[idx]);
        }

        sortInt(array, ++idx, size);
    }
}
