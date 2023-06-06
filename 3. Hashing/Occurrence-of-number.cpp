// Occurrence of number in an array using Hashing.

// Time Complexity : O(n+q)
// Space Complexity : O(n)

#include <iostream>
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
    int hash[1000000] = {0}; // arr[10^6] for int {in main()} but arr[10^7] {globally} whereas arr[10^7] for bool {in main()} but arr[10^8] {globally}
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cout << "How many element's occurrence you want to check? ";
    cin >> q;
    while(q--){
        int num;
        cout << "Enter element you want to check: ";
        cin >> num;
        // Fetching
        cout << num << " : " << hash[num] << endl;
    }

    return 0;
}