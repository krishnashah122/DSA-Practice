// Critical Connections in a Network (Leetcode)
// Leetcode Link : https://leetcode.com/problems/critical-connections-in-a-network/description/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
public:
    int timer = 1;

    void dfs(vector<vector<int>> &adj, int parent, int node, vector<bool> &visited, vector<int> &discoverTime, vector<int> &lowestTime, vector<vector<int>> &bridges){
        // Step 1: Mark the current node as visited and set its discover and lowest time
        visited[node] = true;
        discoverTime[node] = lowestTime[node] = timer;
        timer++;

        // Step 2: Explore all neighbors of the current node
        for (int neighbor : adj[node]) {
            // Step 3: Skip the parent node to prevent re-traversing the edge to the parent
            if (neighbor == parent) continue;

            // Step 4: If the neighbor is unvisited, recursively perform DFS
            if (!visited[neighbor]) {
                dfs(adj, node, neighbor, visited, discoverTime, lowestTime, bridges);
                
                // Step 5: Update the lowest time of the current node based on the neighbor
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbor]);

                // Step 6: Check if the edge is a bridge
                if (lowestTime[neighbor] > discoverTime[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                // Step 7: Update the lowest time of the current node if the neighbor is already visited
                lowestTime[node] = min(lowestTime[node], discoverTime[neighbor]);
            }
        }

        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        vector<int> discoverTime(n); // To store the discover time of each node
        vector<int> lowestTime(n); // To store the lowest reachable time for each node
        vector<vector<int>> bridges;

        // Step 1: Build the adjacency list from the given connections
        for (auto connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Start DFS traversal from node 0
        dfs(adj, -1, 0, visited, discoverTime, lowestTime, bridges);

        // Step 3: Return the list of bridges
        return bridges;
    }
};