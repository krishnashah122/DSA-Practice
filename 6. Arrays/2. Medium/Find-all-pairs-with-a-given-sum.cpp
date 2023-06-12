// Find all pairs with a given sum (GFG)
// GFG Link : https://bit.ly/3SVYU8f

// Time Complexity : O(NLogN) if N > M or O(MLogM) if M > N
// Space Complexity : O(min(N, M))

class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        sort(A, A+N);
        sort(B, B+M);
        
        vector<pair<int, int>> ans;
        int left = 0;
        int right = M-1;
        int sum = 0;
        
        while(left < N && right >= 0){
            sum = A[left] + B[right];
            if(sum == X){
                ans.push_back({A[left], B[right]});
                left++;
                right--;
            }
            else if(sum < X){
                left++;
            }
            else if(sum > X){
                right--;
            }
        }
        return ans;
    }
};