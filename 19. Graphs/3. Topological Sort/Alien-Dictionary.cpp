// Alien Dictionary (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Time Complexity : O(N + V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>> &adj, int V){
        vector<int> indegree(V, 0);
        vector<int> topoOrder;
        queue<int> q;
        
        // Step 1: Calculate indegree for all nodes
        for(int i = 0; i < V; i++){
            for(int neighbor : adj[i]){
                indegree[neighbor]++;
            }
        }
        
        // Step 2: Enqueue nodes with indegree 0
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // Step 3: Perform BFS to generate topological order
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Return the topological Order
        return topoOrder;
    }
  
    string findOrder(vector<string> dict, int k) {
        // code here
        int N = dict.size();
        vector<vector<int>> adj(k);
        
        // Step 1: Build the adjacency list based on dictionary order
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            bool foundDiff = false;
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    foundDiff = true;
                    break;
                }
            }
            
            if(!foundDiff && s1.size() > s2.size()) return ""; // Invalid case
        }
        
        // Step 2: Get the topological order
        vector<int> topo = topologicalSort(adj, k);
        
        // Step 3: Convert topological order to the resulting string
        string result;
        for(int node : topo){
            result += (char) (node + 'a');
        }
        
        // Step 4: Return the result
        return result;
    }
};