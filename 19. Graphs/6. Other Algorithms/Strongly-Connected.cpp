// Strongly Connected (GFG)
// GFG Link : https://shorturl.at/kHztO

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int node, stack<int> &st, vector<bool> &visited){
        visited[node] = true;
        
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(adj, neighbor, st, visited);
            }
        }
        
        st.push(node);
        
        return;
    }
    
    void reversedDFS(vector<vector<int>> &reverseAdj, int node, vector<bool> &visited){
        visited[node] = true;
        
        for(int neighbor : reverseAdj[node]){
            if(!visited[neighbor]){
                reversedDFS(reverseAdj, neighbor, visited);
            }
        }
        
        return;
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<vector<int>> reverseAdj(V);
        vector<bool> visited(V, false);
        stack<int> st;
        int countSCC = 0;
        
        // Step 1: Perform DFS and store nodes in stack by their finish time
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj, i, st, visited);
            }
        }
        
        // Step 2: Create a reversed graph
        for(int i = 0; i < V; i++){
            for(int neighbor : adj[i]){
                reverseAdj[neighbor].push_back(i);
            }
        }
        
        fill(visited.begin(), visited.end(), false); // Reset visited array
        
        // Step 3: Perform DFS on reverse graph in stack order to find SCCs
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                countSCC++;
                reversedDFS(reverseAdj, node, visited);
            }
        }
        
        // Step 4: Return the total no. of strongly connected components
        return countSCC;
    }
};