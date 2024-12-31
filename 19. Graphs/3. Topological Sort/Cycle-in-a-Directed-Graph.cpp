// Cycle in a Directed Graph (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
  public:
    bool hasCycle(vector<vector<int>>& adj, stack<int> &st, vector<bool> &visited, vector<bool> &path){
        int node = st.top();
        st.pop();
        
        // Step 1: Mark the current node as visited and part of the current path
        visited[node] = true;
        path[node] = true;

        // Step 2: Explore all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);

                // Step 3: Recursively check for a cycle
                if (hasCycle(adj, st, visited, path)) {
                    return true;
                }
                
            } else if (path[neighbor]) {
                // Step 4: A cycle is detected if a node is already in the current path
                return true;
            }
        }

        // Step 5: Remove the current node from the path before returning
        path[node] = false;

        // Step 6: No cycle found for the current node, return false
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        // // 1. BFS Approach (Kahn's Algorithm)
        // vector<int> indegree(V, 0);
        // queue<int> q;
        // int count = 0;
    
        // // Step 1: Calculate indegree of each vertex
        // for (int i = 0; i < V; i++) {
        //     for (int neighbor : adj[i]) {
        //         indegree[neighbor]++;
        //     }
        // }
    
        // // Step 2: Add vertices with indegree 0 to the queue
        // for (int i = 0; i < V; i++) {
        //     if (indegree[i] == 0) {
        //         q.push(i);
        //     }
        // }
    
        // // Step 3: Perform BFS to process the vertices in topological order
        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     count++;
    
        //     // Step 4: Decrease indegree of neighbors and add to queue if indegree becomes 0
        //     for (int neighbor : adj[node]) {
        //         indegree[neighbor]--;
        //         if (indegree[neighbor] == 0) {
        //             q.push(neighbor);
        //         }
        //     }
        // }
    
        // // Step 5: If all vertices are not processed, a cycle exists
        // return count != V;

        
        
        // 2. DFS Approach
        // Step 1: Initialize visited and path tracking arrays
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        stack<int> st;

        // Step 2: Start DFS from all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                st.push(i);
                if (hasCycle(adj, st, visited, path)) {
                    return true;
                }
            }
        }

        // Step 3: Return false if no cycle is detected
        return false;
    }
};