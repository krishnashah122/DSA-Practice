// Selection Sort (Code Studio)

// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = 0; i < arr.size(); i++){
        int min_index = i;
        // Iterating through the array to find the index of min element.
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        // Swapping the min element with its correct position.
        swap(arr[min_index], arr[i]);
    }
}