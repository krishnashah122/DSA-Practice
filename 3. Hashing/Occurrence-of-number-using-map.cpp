// Occurrence of number using map in Hashing.

// Time Complexity for map : O(Logn)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Precomputing
    map<int, int> mpp; // Map stores all the values in sorted order
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // Printing map by iterating it
    for(auto it: mpp){
        cout << it.first << " : " << it.second << endl;
    }

    int q;
    cout << "How many element's occurrence you want to check? ";
    cin >> q;
    while(q--){
        int num;
        cout << "Enter element you want to check: ";
        cin >> num;
        // Fetching
        cout << num << " : " << mpp[num] << endl;
    }

    return 0;
}