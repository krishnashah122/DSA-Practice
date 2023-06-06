// Selection Sort using Recursion
// Parameterized Recursion

#include <iostream>
using namespace std;

void selectionSort(int *arr, int i, int j, int max){
    if(i == 0){
        return;
    }
    if(j < i){
        if(arr[j] > arr[max]){
            selectionSort(arr, i, j + 1, j);
        }else{
            selectionSort(arr, i, j + 1, max);
        }
    }else{
        int temp = arr[max];
        arr[max] = arr[i - 1];
        arr[i - 1] = temp;
        selectionSort(arr, i - 1, 0 , 0);
    }
}

int main(){
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n, 0, 0);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}