// Dijkstra Algorithm (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Time Complexity : O(E * LogV)
// Space Complexity : O(V)

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, INT_MAX);

        // Step 1: Push the source vertex into the priority queue and set its distance to 0
        pq.push({0, src});
        distance[src] = 0;

        // Step 2: Process vertices in the priority queue
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Step 3: Relax edges of the current vertex
            for(auto neighbor : adj[node]){
                int vertex = neighbor.first;
                int wt = neighbor.second;
                
                // Step 4: Update the distance if a shorter path is found and push into the queue
                if(weight + wt < distance[vertex]){
                    distance[vertex] = weight + wt;
                    pq.push({distance[vertex], vertex});
                }
            }
        }
        
        // Step 5: Return the final shortest distances
        return distance;
    }
};