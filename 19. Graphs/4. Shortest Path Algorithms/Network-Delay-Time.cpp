// Network Delay Time (Leetcode)
// Leetcode Link : https://leetcode.com/problems/network-delay-time/description/

// Time Complexity : O(E * Logn)
// Space Complexity : O(E + n)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Initialize adjacency list, priority queue, and distance vector
        vector<vector<pair<int, int>>> adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n+1, INT_MAX);

        // Step 2: Start with the source node k and set its distance to 0
        pq.push({0, k});
        distance[k] = 0;

        // Step 3: Build the adjacency list from the given times input
        for(auto edge : times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Step 4: Process nodes using Dijkstra's algorithm
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Step 5: Update distances for neighbors if a shorter path is found
            for(auto neighbor : adj[node]){
                int vertex = neighbor.first;
                int time = neighbor.second;

                if(dist + time < distance[vertex]){
                    distance[vertex] = dist + time;
                    pq.push({distance[vertex], vertex});
                }
            }
        }

        // Step 6: Find the maximum time needed to reach all nodes or return -1 if unreachable
        int minTimeForAll = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(distance[i] == INT_MAX) return -1;
            minTimeForAll = max(minTimeForAll, distance[i]);
        }

        // Step 7: Return the minimum time needed to reach all nodes
        return minTimeForAll;
    }
};