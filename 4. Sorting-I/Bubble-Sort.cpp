// Bubble Sort (Code Studio & GFG)
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/bubble-sort_980524
// GFG Link : https://bit.ly/3w6yQx8

// Best Time Complexity : O(n)
// Average & Worst Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = n-1; i >= 0; i--){
        int didSwap = 0;
        // Checking two adjacent elements and swapping them.
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        // If swap not happened then break the loop.
        if(didSwap == 0){
            break;
        }
    }
}

