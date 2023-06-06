// Check whether the array is sorted or not.

#include <iostream>
using namespace std;

bool checkSorted(int *arr, int i, int n){
    if(i == n-1){
        return true;
    }
    return arr[i] < arr[i+1] && checkSorted(arr, i + 1, n);
}

int main(){
    int arr[] = {1, 2, 3, 8, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(checkSorted(arr, 0, n)){
        cout << "The array is sorted.";
    }else{
        cout << "The array is not sorted.";
    }
    return 0;
}