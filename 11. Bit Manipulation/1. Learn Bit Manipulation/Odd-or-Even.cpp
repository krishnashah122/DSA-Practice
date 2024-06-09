// Odd or Even (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/odd-or-even3618/1

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution{   
public:
    string oddEven(int N){
        // code here 
        // Check the last bit of N, if it is 1 then odd number and if it is 0 then even number
        if(N & 1){
            return "odd";
        }else{
            return "even";
        }
    }
};