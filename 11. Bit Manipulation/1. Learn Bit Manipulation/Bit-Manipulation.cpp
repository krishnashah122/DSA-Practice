// Bit Manipulation (GFG)
// GFG Link : https://shorturl.at/wi6FZ

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int ithBit = (num >> i-1) & 1;
        int setBit = num | (1 << i-1);
        int clearBit = num & ~(1 << i-1);
        
        cout << ithBit << ' ' << setBit << ' ' << clearBit;
    }
};