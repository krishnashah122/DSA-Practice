// Swap two numbers (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        // Ex: a = 13, b = 9
        a = a ^ b; // (13 ^ 9)
        b = a ^ b; // {(13 ^ 9) ^ 9}
        a = a ^ b; // [(13 ^ 9) ^ {(13 ^ 9) ^ 9}]
        return {a, b};
    }
};