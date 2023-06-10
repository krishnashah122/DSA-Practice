// Insertion Sort (Code Studio & GFG)
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179
// GFG Link : https://bit.ly/3JVcqot

// Best Time Complexity : O(n)
// Average & Worst Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i = 0; i < arr.size(); i++){
        int j = i;
        // Checking and placing unsorted element at its correct place.
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}