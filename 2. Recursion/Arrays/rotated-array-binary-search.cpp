// Rotated array Binary Search using Recursion.
// Parameterized Recursion

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int s, int e, int target){
    if(s > e){
        return -1;
    }
    int mid = s+(e-s)/2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[s] <= arr[mid]){
        if(arr[mid] >= target && arr[s] <= target){
            return binarySearch(arr, s, mid - 1, target);
        }else{
            return binarySearch(arr, mid + 1, e, target);
        }
    }
    
    if(arr[mid] <= target && arr[e] >= target){
        return binarySearch(arr, mid + 1, e, target);
    }
    return binarySearch(arr, s, mid - 1, target);
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 8, 1, 2, 3};
    cout << binarySearch(arr, 0, arr.size()-1, 6);
    return 0;
}