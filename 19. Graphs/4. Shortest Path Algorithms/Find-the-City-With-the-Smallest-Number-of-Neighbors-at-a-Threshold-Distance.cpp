// Find the City With the Smallest Number of Neighbors at a Threshold Distance (Leetcode)
// Leetcode Link : https://shorturl.at/VHD41

// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix with a large value and set diagonal to 0
        vector<vector<int>> distance(n, vector<int>(n, 1e5));

        for(int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        // Step 2: Populate the distance matrix with edge weights
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            distance[u][v] = weight;
            distance[v][u] = weight; // For undirected graph
        }

        // Step 3: Apply Floyd-Warshall Algorithm to compute shortest distances
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][via] + distance[via][j]);
                }
            }
        }

        // Step 4: Count reachable cities within the distance threshold for each city
        vector<int> reachableCities(n);
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && distance[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            reachableCities[i] = count;
        }

        // Step 5: Find the city with the smallest number of reachable cities
        int minReachable = INT_MAX;
        int leastReachableCity = 0;
        for(int i = 0; i < n; i++) {
            if(reachableCities[i] <= minReachable) {
                minReachable = reachableCities[i];
                leastReachableCity = i; // Choose the largest index in case of a tie
            }
        }

        // Step 6: Return the city with the smallest number of reachable cities
        return leastReachableCity;
    }
};