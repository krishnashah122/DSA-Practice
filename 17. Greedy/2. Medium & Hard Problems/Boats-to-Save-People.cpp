// Boats to Save People (Leetcode)
// Leetcode Link : https://leetcode.com/problems/boats-to-save-people/description/

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Step 1: Sort people by weight in ascending order
        sort(people.begin(), people.end());
        int boats = 0;

        int i = 0;
        int j = people.size()-1;
        
        // Step 2: Pair heaviest person with the lightest if within limit
        while(i <= j){
            if(people[j] + people[i] <= limit){
                i++; // Pair lightest with heaviest
            }
            j--; // Always take the heaviest
            boats++; // Increment boat count
        }

        return boats;
    }
};