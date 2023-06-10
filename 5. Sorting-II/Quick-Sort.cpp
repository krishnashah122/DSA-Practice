// Quick Sort (Code Studio & GFG)
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/quick-sort_983625
// GFG Link : https://bit.ly/3dsEbIK

// Best & Average Time Complexity : O(nlogn)
// Worst Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        // Increment i until arr[i] > pivot, then stop
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        // Decrement j until arr[j] < pivot, then stop
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSortFunction(vector <int> &arr, int low, int high){
    // Checking if range is > 1
    if(low < high){
        int pIndex = partition(arr, low, high);
        // Left Subarray
        quickSortFunction(arr, low, pIndex-1);
        // Right Subarray
        quickSortFunction(arr, pIndex+1, high);
    }
}

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector <int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    cout << "Sorted array: ";
    quickSortFunction(arr, 0, arr.size()-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}