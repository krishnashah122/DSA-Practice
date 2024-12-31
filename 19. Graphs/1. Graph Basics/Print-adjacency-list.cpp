// Print adjacency list (GFG)
// GFG Link : https://shorturl.at/OZ7Kv

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        // Step 1: Initialize the adjacency list with V empty lists
        vector<vector<int>> adjacencyList(V);
        
        // Step 2: Iterate through the edges to populate the adjacency list
        for(auto pair : edges){
            adjacencyList[pair.first].push_back(pair.second); // Add edge from first to second vertex
            adjacencyList[pair.second].push_back(pair.first); // Add edge from second to first vertex (undirected graph)
        }
        
        // Step 3: Return the populated adjacency list
        return adjacencyList;
    }
};