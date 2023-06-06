// Binary Search using Recursion.

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
    }else if(arr[mid] > target){
        e = mid - 1;
    }else{
        s = mid + 1;
    }
    return binarySearch(arr, s, e, target);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << binarySearch(arr, 0, arr.size()-1, 4);
    return 0;
}