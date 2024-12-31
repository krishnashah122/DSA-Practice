// DFS of Graph (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
  public:
    // Function to perform DFS traversal
    void dfs(vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st, vector<int> &ans){
        // Step 1: Pop the top node, mark it as visited & add it in result
        int node = st.top();
        st.pop();
        visited[node] = true;
        ans.push_back(node);
        
        // Step 2: Push unvisited neighbors onto the stack and recurse
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                dfs(adj, visited, st, ans);
            }
        }
        
        return;
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        // Step 1: Initialize visited array, result vector, and stack
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        stack<int> st;
        
        // Step 2: Start DFS from the first node
        st.push(0);
        dfs(adj, visited, st, ans);
        
        // Step 3: Return the DFS result
        return ans;
    }
};