// All divisors of a Number (GFG)
// GFG Link : https://shorturl.at/rrCwo

// Time Complexity : O(sqrt(n))
// Space Complexity : O(sqrt(n))

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> divisors;
        
        // Store the divisors upto square root of n
        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
            }
        }
        
        // Print the divisors upto square root of n
        for(int i = 0; i < divisors.size(); i++){
            cout << divisors[i] << " ";
        }
        
        // Print the divisors form square root of n to n
        for(int i = divisors.size() - 1; i >= 0; i--){
            if(n / divisors[i] != divisors[i]){
                cout << n / divisors[i] << " ";
            }
        }
    }
};