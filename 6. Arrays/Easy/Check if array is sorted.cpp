// Check if array is sorted (GFG)

// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        for(int i = 0; i < n-1; i++){
            if(arr[i] <= arr[i+1]){
                
            }else{
                return false;
            }
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}