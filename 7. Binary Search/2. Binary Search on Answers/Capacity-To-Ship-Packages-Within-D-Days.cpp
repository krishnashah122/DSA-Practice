// Capacity To Ship Packages Within D Days (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// GFG Link : https://bit.ly/3PBInmS

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

class Solution {
public:
    // function to check whether 'weightCapacity' capacity is possible or not
    int findDays(vector<int>& weights, int weightCapacity, int days){
        int daysNeed = 1; // count days required to ship with the capacity of weightCapacity
        int weightPerDay = 0; // count the weight that can be shipped for a particular day
        
        for(int i = 0; i < weights.size(); i++){ // O(n)
            // if weightPerDay + weights[i] exceeds the weightCapacity
            if(weightPerDay + weights[i] > weightCapacity){
                daysNeed++; // increased to next day
                weightPerDay = weights[i];
            }
            // if weightPerDay + weights[i] doesn't exceeds the weightCapacity
            else{
                weightPerDay += weights[i]; // add weights[i] with weightPerDay of current dayNeed
            }
        }
        return daysNeed;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;
        for(int i = 0; i < weights.size(); i++){ // O(n)
            low = max(low, weights[i]);
            high += weights[i];
        }

        while(low < high){ // O(Logm)
            int mid = low + (high - low) / 2;

            int noOfDays = findDays(weights, mid, days);

            // if required days to ship with the capacity of 'mid' is less than or equal to given days
            if(noOfDays <= days){
                high = mid; // to search in left part including mid
            }
            // if required days to ship with the capacity of 'mid' is more than the given days
            else{
                low = mid + 1; // to search in right part
            }
        }
        return low;
    }
};