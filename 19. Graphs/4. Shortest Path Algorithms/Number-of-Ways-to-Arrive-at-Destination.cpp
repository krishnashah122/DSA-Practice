// Number of Ways to Arrive at Destination (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

// Time Complexity : O(E * Logn)
// Space Complexity : O(E + n)

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        
        // Step 1: Create adjacency list for the graph
        vector<vector<pair<int, long long>>> adj(n);
        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // Step 2: Initialize data structures for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Step 3: Set up starting node (node 0)
        pq.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        // Step 4: Process nodes using priority queue
        while(!pq.empty()) {
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Step 5: Update time and ways for neighbors
            for(auto neighbor : adj[node]) {
                int vertex = neighbor.first;
                long long wt = neighbor.second;

                // Step 6: Found a shorter path to the vertex, update time and ways
                if(t + wt < time[vertex]) {
                    time[vertex] = t + wt;
                    ways[vertex] = ways[node];
                    pq.push({time[vertex], vertex});
                } else if(t + wt == time[vertex]) {
                    // Step 7: Found another path with the same shortest time, add the number of ways
                    ways[vertex] = (ways[vertex] + ways[node]) % mod;
                }
            }
        }

        // Step 8: Return the number of ways to reach the last node
        return ways[n-1];
    }
};