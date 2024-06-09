// Two numbers with odd occurrences (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        // XOR all the elements
        long long int XORR = 0;
        for(int i = 0; i < N; i++){
            XORR ^= Arr[i];
        }
        
        // Find the rightmost set bit of XOR
        int rightMostSet = (XORR & XORR - 1) ^ XORR;
        int bucket1 = 0;
        int bucket2 = 0;
        for(int i = 0; i < N; i++){
            if(Arr[i] & rightMostSet){
                // XOR all the elements having set bit at the same position where XORR has its rightmost set bit
                bucket1 ^= Arr[i];
            }else{
                // XOR all the elements having unset bit at the same position where XORR has its rightmost set bit
                bucket2 ^= Arr[i];
            }
        }
        
        if(bucket1 > bucket2){
            return {bucket1, bucket2};
        }else{
            return {bucket2, bucket1};
        }
    }
};