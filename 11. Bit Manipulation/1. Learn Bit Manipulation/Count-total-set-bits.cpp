// Count total set bits (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        // Base case: if n is 0, there are no set bits to count
        if(n == 0) return 0;
        
        int p = 0;
        // Find the largest power of 2 less than or equal to n
        while(n >= pow(2, p)){
            p++;
        }
        p--; // Decrement p to get the correct power
        
        // Calculate the total set bits in two parts:
        // 1. Set bits in numbers from 1 to 2^p - 1
        // 2. Set bits in numbers from 2^p to n
        int totalSetBits = ((pow(2, p) / 2) * p) + (n - pow(2, p) + 1) + countSetBits(n - pow(2, p));
        return totalSetBits;
    }
};