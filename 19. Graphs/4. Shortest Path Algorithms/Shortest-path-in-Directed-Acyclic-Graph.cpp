// Shortest path in Directed Acyclic Graph (GFG)
// GFG Link : https://shorturl.at/ek3q1

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> topoOrder;
        vector<int> visited(V, INT_MAX);
        visited[0] = 0; // Initialize the source distance to 0
        
        // Step 1: Build graph and compute indegrees
        for(int i = 0; i < E; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            indegree[edges[i][1]]++;
        }
        
        // Step 2: Perform topological sorting using (BFS)
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for(auto neighbor : adj[node]){
                int vertex = neighbor.first;
                indegree[vertex]--;
                if(indegree[vertex] == 0){
                    q.push(vertex);
                }
            }
        }
        
        // Step 3: Relax edges in topological order
        for(int node : topoOrder){
            if(visited[node] != INT_MAX){
                for(auto neighbor : adj[node]){
                    int vertex = neighbor.first;
                    int wt = neighbor.second;
                    
                    if(visited[node] + wt < visited[vertex]){
                        visited[vertex] = visited[node] + wt;
                    }
                }
            }
        }
        
        // Step 4: Replace unreachable node's distance with -1
        for(int i = 0; i < V; i++){
            if(visited[i] == INT_MAX){
                visited[i] = -1;
            }
        }
        
        // Step 5: Return the visited array
        return visited;
    }
};