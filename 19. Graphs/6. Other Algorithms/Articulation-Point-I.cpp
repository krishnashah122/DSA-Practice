// Articulation Point - I (GFG)
// GFG Link : https://shorturl.at/xjpkr

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
  public:
    int timer = 0;
    
    void dfs(vector<int> adj[], int parent, int node, vector<int> &discoverTime, vector<int> &lowestTime, vector<bool> &visited, vector<bool> &markAP){
        // Step 1: Mark the current node as visited and initialize its discovery and lowest time
        visited[node] = true;
        discoverTime[node] = lowestTime[node] = timer;
        timer++;
        int child = 0;
        
        // Step 2: Explore all neighbors of the current node
        for(int neighbor : adj[node]) {
            // Step 3: Skip the edge to the parent node
            if(neighbor == parent) continue;
            
            if(!visited[neighbor]) {
                // Step 4: Perform DFS for unvisited neighbors
                dfs(adj, node, neighbor, discoverTime, lowestTime, visited, markAP);
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbor]);
                
                // Step 5: Check if the current node is an articulation point
                if(discoverTime[node] <= lowestTime[neighbor] && parent != -1) {
                    markAP[node] = true;
                }
                
                child++;
            } else {
                // Step 6: Update the lowest time for visited neighbors
                lowestTime[node] = min(lowestTime[node], discoverTime[neighbor]);
            }
        }
        
        // Step 7: Special case for root node
        if(parent == -1 && child > 1) {
            markAP[node] = true;
        }
        
        return;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> discoverTime(V); // To store the discover time of each node
        vector<int> lowestTime(V); // To store the lowest reachable time for each node
        vector<bool> markAP(V, false); // To mark the articulation points
        vector<int> articulationPoints;
        
        // Step 1: Start DFS from all unvisited nodes
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(adj, -1, i, discoverTime, lowestTime, visited, markAP);
            }
        }
        
        // Step 2: Collect all articulation points
        for(int i = 0; i < V; i++) {
            if(markAP[i]) {
                articulationPoints.push_back(i);
            }
        }
        
        // Step 3: Return -1 if no articulation points found
        if(articulationPoints.size() == 0) {
            return {-1};
        }
        
        // Step 4: Return the list of articulation points
        return articulationPoints;
    }
};