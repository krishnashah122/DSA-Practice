// Merge k Sorted Arrays (GFG)
// GFG Link : https://shorturl.at/TgVw7

// Time Complexity : O(k^2 * Logk)
// Space Complexity : O(k^2)

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> sorted;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < K; i++){
            for(int j = 0; j < K; j++){
                // Push each element into the Min Heap
                minHeap.push(arr[i][j]);
            }
        }
        
        // Extract elements from the Min Heap and add them to the sorted array
        while(!minHeap.empty()){
            int element = minHeap.top();
            minHeap.pop();
            sorted.push_back(element);
        }
        
        return sorted;
    }
};