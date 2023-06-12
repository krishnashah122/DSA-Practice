// Longest Sub-Array with Sum K (GFG)
// GFG Link : https://bit.ly/43AAExc

// Time Complexity : O(nLogn)
// Space Complexity : O(n)

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function

        // map will store the prefix sums and the indices
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for(int i = 0; i < N; i++){
            // calculate prefix sum till index i
            sum += A[i];

            // if sum == K then update the max length of subarray
            if(sum == K){
                maxLen = max(maxLen, i+1);
            }

            // calculate the prefix sum (i.e., x-k) of remaining subarray
            int rem = sum - K;

            // check whether the prefix sum of remaining subarray (x-k) is present in the preSumMap or not.
            if(preSumMap.find(rem) != preSumMap.end()){
                // if remaining subarray's prefix sum (x-k) is present then calculate the length (i.e., i - preSumMap[rem]) and update the max length after comparing
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // if the prefix sum of remaining subarray (x-k) is not present then add it in the preSumMap
            // update the preSumMap after checking the conditions
            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    } 

};