// Minimum Number of Days to Make m Bouquets (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// GFG Link : https://bit.ly/3CJ9Ezm

// Time Complexity : O(nLogx)
// Space Complexity : O(1)

class Solution {
public:
    // function to count the no. of bouquets that can be made in 'day' days
    int countBouquets(vector<int>& bloomDay, int day, int k){
        int count = 0;
        int bouquetsNum = 0;
        // count the no. of bouquets
        for(int i = 0; i < bloomDay.size(); i++){ // O(n)
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                bouquetsNum += (count / k);
                count = 0;
            }
        }
        bouquetsNum += (count / k);
        return bouquetsNum;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        // find the min and max element in the array assign it to mini and maxi respectively
        for(int i = 0; i < bloomDay.size(); i++){ // O(n)
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        long long required = m * 1ll * k * 1ll; // to avoid overflow
        // if the elements are less than the required elements to make m bouquets
        if(bloomDay.size() < required) return -1;

        int low = mini;
        int high = maxi;

        while(low < high){ // O(x)
            int mid = low + (high - low) / 2;

            if(countBouquets(bloomDay, mid, k) < m){
                low = mid + 1; // to search in right part
            }
            else{
                high = mid; // to search in left part including mid
            }
        }
        return low;
    }
};