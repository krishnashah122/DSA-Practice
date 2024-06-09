// Set the rightmost unset bit (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        return N | N + 1;
    }
};