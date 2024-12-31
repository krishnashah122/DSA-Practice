// Topological sort (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/topological-sort/1

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int node, stack<int> &st, vector<bool> &visited){
        // Step 1: Mark the current node as visited
        visited[node] = true;
        
        // Step 2: Recursively call DFS for unvisited neighbors
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(adj, neighbor, st, visited);
            }
        }
        
        // Step 3: Push the current node onto the stack after processing all neighbors
        st.push(node);
        
        return;
    }
  
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        // // 1. BFS Approach (Kahn's Algorithm)
        // int V = adj.size();
        // vector<int> indegree(V, 0);
        // queue<int> q;
        // vector<int> topoOrder;
    
        // // Step 1: Compute in-degrees of all vertices
        // for (int i = 0; i < V; i++) {
        //     for (int neighbor : adj[i]) {
        //         indegree[neighbor]++;
        //     }
        // }
    
        // // Step 2: Add vertices with 0 in-degree to the queue
        // for (int i = 0; i < V; i++) {
        //     if (indegree[i] == 0) {
        //         q.push(i);
        //     }
        // }
    
        // // Step 3: Process the queue in BFS manner
        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     topoOrder.push_back(node);
    
        //     // Step 4: Update in-degrees of neighbors and enqueue if 0
        //     for (int neighbor : adj[node]) {
        //         indegree[neighbor]--;
        //         if (indegree[neighbor] == 0) {
        //             q.push(neighbor);
        //         }
        //     }
        // }
    
        // // Step 5: Return the topological order
        // return topoOrder;
        
        
        // 2. DFS Approach
        int V = adj.size();
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> topoOrder;
        
        // Step 1: Perform DFS for all unvisited nodes
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj, i, st, visited);
            }
        }
        
        // Step 2: Extract topological order from the stack
        while(!st.empty()){
            topoOrder.push_back(st.top());
            st.pop();
        }
        
        // Step 3: Return the topological order
        return topoOrder;
    }
};