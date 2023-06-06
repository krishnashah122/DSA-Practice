// Reverse an Array using Recursion.
// Parameterized Recursion

#include <iostream>
#include <vector>
using namespace std;

void reverse(int a[], int s, int e){
    if(s >= e){
        return;
    }
    int temp = a[s];
    a[s] = a[e];
    a[e] = temp;
    reverse(a, s + 1, e - 1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}