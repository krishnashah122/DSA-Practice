// Koko Eating Bananas (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/koko-eating-bananas/description/
// GFG Link : https://bit.ly/3LSY491

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1;

        // find the maximum element in the array assign it to high
        for(int pile : piles){ // O(n)
            high = max(high, pile);
        }

        while(low < high){ // O(Logm)
            int mid = low + (high - low) / 2;

            // calculate the total hours to eat all bananas if mid no. of bananas eaten/hour
            int totalHour = 0;
            for(int pile : piles){ // O(n)
                totalHour += ceil((double)(pile) / (double)(mid));
            }

            // if totalHour <= given time, search in left part to find minimum no. of bananas can be eaten per hour
            if(totalHour <= h){
                high = mid; // to search in left part including mid
            }
            // if totalHour > given time, search in right part to find minimum no. of bananas can be eaten per hour
            else{
                low = mid + 1; // to search in right part
            }
        }
        return low;
    }
};