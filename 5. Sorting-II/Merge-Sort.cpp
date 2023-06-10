// Merge Sort (Code Studio & GFG)
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/merge-sort_920442
// GFG Link : https://bit.ly/3A30Anw

// Time Complexity : O(logn)
// Space Complexity : O(n)
// Auxiliary Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(vector < int > &arr, int low, int mid, int high){
    vector <int> temp; // Empty Array
    int left = low; // Starting index of left half array
    int right = mid+1; // Starting index of right half array

    // Two halves : [low to mid] and [mid+1 to high]
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copying left-out elements from left half
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    // Copying left-out elements form right half
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // Inserting form temp array to original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector < int > & arr, int low, int high) {
    // Write your code here.

    // Base Case
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;

    // Left Half
    mergeSort(arr, low, mid);
    // Right Half
    mergeSort(arr, mid+1, high);
    // Merge the Left and Right Half returned array
    merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}