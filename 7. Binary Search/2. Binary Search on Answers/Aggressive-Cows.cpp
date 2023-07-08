// Aggressive Cows (GFG)
// GFG Link : https://bit.ly/3rBuE5Z

// Time Complexity : O(nLogn + nLogm)
// Space Complexity : O(1)

class Solution {
public:
    // function to check whether cows can be placed with distance 'gap' or not
    bool isPossible(vector<int>& stalls, int gap, int cows){
        int placedCows = 1;
        int lastPlaced = stalls[0];
        // count the no. of cows that can be placed
        for(int i = 0; i < stalls.size(); i++){ // O(n)
            // if gap is less than or equal to the difference between lastPlaced and stalls[i]
            if(gap <= stalls[i] - lastPlaced){
                placedCows++;
                lastPlaced = stalls[i];
            }
            
            // if placedCows is equal to the no. of cows that needed to be placed then return true
            if(placedCows == cows) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        // sort the array
        sort(stalls.begin(), stalls.end()); // O(nLogn)
        
        int low = 1;
        int high = stalls[n-1];
        while(low <= high){ // O(Logm)
            int mid = low + (high - low) / 2;
            
            // if k no. of cows are placed with the distance of 'mid'
            if(isPossible(stalls, mid, k)){
                low = mid + 1; // to search in right part
            }
            // if k no. of cows are not placed with the distance of 'mid'
            else{
                high = mid - 1; // to search in left part
            }
        }
        return high;
    }
};