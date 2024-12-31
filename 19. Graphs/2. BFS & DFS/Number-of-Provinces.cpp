// Number of Provinces (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-provinces/description/

// Time Complexity : O(V^2)
// Space Complexity : O(V)

class Solution {
public:
    // Function to perform DFS to explore all nodes in a connected component
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool> &visited){
        // Step 1: Traverse all unvisited nodes in the connected component
        for (int vertex : isConnected[node]) {
            if (!visited[vertex]) {
                visited[vertex] = true; // Mark vertex as visited
                dfs(isConnected, vertex, visited); // Recur for adjacent nodes
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // Step 1: Get the no. of nodes & build adjacency list from isConnected matrix
        int V = isConnected.size();
        vector<vector<int>> adjList(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Step 2: Initialize visited array & total province counter
        vector<bool> visited(V, false);
        int totalProvinces = 0;

        // Step 3: Traverse all nodes & count connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                totalProvinces++; // Increment province count
                visited[i] = true; // Mark node as visited
                dfs(adjList, i, visited); // Explore all connected nodes
            }
        }

        // Step 4: Return the total number of provinces
        return totalProvinces;
    }
};