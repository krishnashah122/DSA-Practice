// Find XOR of numbers from L to R (GFG)
// GFG Link : https://shorturl.at/OCxzj

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
  public:
    int func(int n){
        if(n % 4 == 1){
            return 1;
        }else if(n % 4 == 2){
            return n + 1;
        }else if(n % 4 == 3){
            return 0;
        }else{
            return n;
        }
    }
    
    int findXOR(int l, int r) {
        // complete the function here
        // The result is the XOR from 0 to (l-1) XORed with the XOR from 0 to r
        return func(l - 1) ^ func(r);
    }
};