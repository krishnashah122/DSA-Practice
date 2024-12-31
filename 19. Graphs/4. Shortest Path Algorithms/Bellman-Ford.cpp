// Bellman-Ford (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Time Complexity : O(V * E)
// Space Complexity : O(V)

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // Step 1: Initialize distance array with infinity and set source distance to 0
        vector<int> distance(V, 1e8);
        distance[src] = 0;
        
        // Step 2: Relax all edges V-1 times
        for(int i = 0; i < V-1; i++) {
            for(auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                // Step 3: Update distance if a shorter path is found
                if(distance[u] != 1e8 && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        
        // Step 4: Relax edges for Vth time to check for negative weight cycle
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            // Step 5: Return {-1} if a negative weight cycle is detected
            if(distance[u] != 1e8 && distance[u] + weight < distance[v]) {
                return {-1};
            }
        }
        
        // Step 6: Return the shortest distance array
        return distance;
    }
};