// Check whether K-th bit is set or not (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int setBit = n & (1 << k);
        if(setBit != 0){
            return true;
        }else{
            return false;
        }
    }
};