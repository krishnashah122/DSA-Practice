// Undirected Graph Cycle (GFG)
// GFG Link : https://shorturl.at/cuzRr

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
  public:
    // 1. BFS Approach
    // bool hasCycle(vector<vector<int>>& adj, int vertex, vector<bool> &visited){
    //     queue<pair<int, int>> q;
    //     q.push({vertex, -1}); // Initialize BFS with the given vertex and mark it visited
    //     visited[vertex] = true;
        
    //     // Step 1: Perform BFS traversal
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
    //         q.pop();
            
    //         // Step 2: Traverse all neighbors of the current node
    //         for(int neighbor : adj[node]){
    //             if(!visited[neighbor]){
    //                 q.push({neighbor, node}); // Visit the unvisited neighbor
    //                 visited[neighbor] = true;
    //             }else if(neighbor != parent){
    //                 return true; // Cycle detected when neighbor is visited and not the parent
    //             }
    //         }
    //     }
        
    //     // Step 3: No cycle detected in this component
    //     return false;
    // }
    
    
    // 2. DFS Approach
    bool detectCycle(vector<vector<int>>& adj, stack<pair<int, int>> &st, vector<bool> &visited){
        int node = st.top().first;
        int parent = st.top().second;
        st.pop();
        visited[node] = true;
            
        // Step 1: Traverse all neighbors of the current node
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                // Step 2: Visit the unvisited neighbor
                st.push({neighbor, node});
                if(detectCycle(adj, st, visited)){
                    return true; // Cycle found
                }
            }else if(neighbor != parent){
                // Step 3: Cycle detected when neighbor is visited and not the parent
                return true;
            }
        }
            
        // Step 4: No cycle found for the current path
        return false;
    }
    
    bool hasCycle(vector<vector<int>>& adj, int vertex, vector<bool> &visited){
        // Step 1: Initialize stack for DFS with the given vertex and parent as -1
        stack<pair<int, int>> st;
        st.push({vertex, -1});
        
        // Step 2: Use the detectCycle function to perform DFS & to check for cycles
        return detectCycle(adj, st, visited);
    }
    
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V, false);
        
        // Step 1: Check for cycles in all connected components
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(hasCycle(adj, i, visited)){
                    return true;
                }
            }
        }
        
        // Step 2: Return false if no cycle is detected in the graph
        return false;
    }
};