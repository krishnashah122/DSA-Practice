// Number of NGEs to the right (GFG)
// GFG Link : https://shorturl.at/0FTcW

// Time Complexity : O(queries * n)
// Space Complexity : O(queries)

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> result(queries);
        
        for(int i = 0; i < queries; i++){
            int counter = 0;
            int idx = indices[i];
            
            for(int j = idx + 1; j < n; j++){
                // If the current element is greater than the element at the given index, increment the counter
                if(arr[j] > arr[idx]){
                    counter++;
                }
            }
            
            // Store the result for the current query
            result[i] = counter;
        }
        
        return result;
    }

};