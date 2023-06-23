// Find Missing And Repeating (GFG)
// GFG Link : https://bit.ly/3zWZoCs

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        // SN = (n * (n+1)) / 2
        long long SN = (n+1);
        SN = (n * SN) / 2;
        
        // S2N = (n * (n+1) * (2*n+1)) / 6
        long long S2N = (2*n+1);
        S2N = (n+1) * S2N;
        S2N = (n*S2N) / 6;
        
        long long sum1 = 0;
        long long sum2 = 0;
        
        for(int i = 0; i < n; i++){ // O(n)
            sum1 += arr[i];
            sum2 += (long long)arr[i] * (long long)arr[i];
        }
        
        long long val1 = sum1 - SN; // x - y
        long long val2 = sum2 - S2N;
        val2 = val2 / val1; // x + y
        long long x = (val1 + val2) / 2; // repeating
        long long y =  x - val1; // missing
        
        return {(int)x, (int)y};
    }
};