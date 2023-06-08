// LCM and GDC/HCF (GFG)

// Algorithm Used : Euclidean
// Time Complexity : O(Log(min(n1, n2)))

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    long long gcd(long long n1, long long n2){
        return n2 ? gcd(n2, n1%n2) : n1; //Euclidean Algorithm
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> ans;
        long long l = 0;
        long long g = gcd(A, B);
        if(g != 0){
            l = A*B/g;
        }
        ans.push_back(l);
        ans.push_back(g);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}