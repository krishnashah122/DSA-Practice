// Shortest Path in Undirected (GFG)
// GFG Link : https://shorturl.at/iyF4k

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        queue<int> q;
        vector<int> visited(V, INT_MAX);
        
        // Step 1: Start BFS from the source node
        visited[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            // Step 2: Process the current node and update its neighbors
            int node = q.front();
            q.pop();
            
            for(int neighbor : adj[node]){
                if(visited[node] + 1 < visited[neighbor]){
                    visited[neighbor] = visited[node] + 1; // Update if shorter path found
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Replace unreachable node's distance with -1
        for(int i = 0; i < V; i++){
            if(visited[i] == INT_MAX){
                visited[i] = -1;
            }
        }
        
        // Step 4: Return the shortest distances
        return visited;
    }
};