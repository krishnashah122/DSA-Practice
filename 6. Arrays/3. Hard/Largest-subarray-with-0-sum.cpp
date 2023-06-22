// Largest subarray with 0 sum (GFG)
// GFG Link : https://bit.ly/3w5QSzC

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int, int> mpp;
        int sum = 0; // store sum
        int maxLen = 0; // store the max length of subarray with 0 sum
        
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            
            if(sum == 0){
                maxLen = i + 1;
            }
            
            // if sum is not in the mpp then add it in the mpp
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
            
            // if sum is present in the mpp then update the maxLen
            if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen, i - mpp[sum]);
            }
        }
        return maxLen;
    }
};