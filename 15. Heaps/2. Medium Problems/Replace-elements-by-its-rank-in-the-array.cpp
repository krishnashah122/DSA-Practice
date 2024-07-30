// Replace elements by its rank in the array (GFG)
// GFG Link : https://shorturl.at/yaGSX

// Time Complexity : O(nLogn)
// Space Complexity : O(n)

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        vector<int> ans(N);
        
        // Insert all elements into the min-heap along with their original indices
        for(int i = 0; i < N; i++){
            minHeap.push({arr[i], i});
        }
        
        int idx = 1;
        int prev = -1;
        // Process elements from the heap and assign ranks
        while(!minHeap.empty()){
            pair<int, int> element = minHeap.top();
            minHeap.pop();
            
            // If the current element is the same as the previous one, use the same rank
            if(element.first == prev){
                idx--;
            }
            
            // Assign the rank to the correct position
            ans[element.second] = idx;
            prev = element.first; // Update previous element value
            idx++; // Increment the rank
        }
        
        return ans;
    }

};