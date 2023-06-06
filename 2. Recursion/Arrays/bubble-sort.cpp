// Bubble Sort using Recursion
// Parameterized Recursion

#include <iostream>
using namespace std;

void bubbleSort(int *arr, int i, int j){
    if(i == 0){
        return;
    }
    if(j < i){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        bubbleSort(arr, i, j + 1);
    }else{
        bubbleSort(arr, i - 1, 0);
    }
}

int main(){
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n - 1, 0);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}