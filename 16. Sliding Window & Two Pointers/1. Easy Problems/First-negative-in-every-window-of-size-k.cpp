// First negative in every window of size k (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Time Complexity : O(n)
// Space Complexity : O(k)

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> q;
    int left = 0;
    
    for(int right = 0; right < N; right++){
        // If the window size exceeds K, move the left boundary
        if(K < (right - left + 1)){
            // If the element to be removed is the same as the front of the queue, pop it
            if(!q.empty() && A[left] == q.front()) q.pop();
            left++; // Move the left boundary to the right
        }
        
        // If the current element is negative, add it to the queue
        if(A[right] < 0) q.push(A[right]);
        
        // When the window size is exactly K, determine the result for this window
        if(K == (right - left + 1)){
            // If queue contains negative numbers, add the front element to the result
            if(!q.empty()){
                ans.push_back(q.front());
            }else{
                // If queue is empty, add 0 to the result
                ans.push_back(0);
            }
        }
    }
    
    return ans;
}