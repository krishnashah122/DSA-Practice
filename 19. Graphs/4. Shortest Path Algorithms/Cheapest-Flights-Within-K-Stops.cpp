// Cheapest Flights Within K Stops (Leetcode)
// Leetcode Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Time Complexity : O(E * Logn)
// Space Complexity : O(E + n)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> minCost(n, INT_MAX);
        pq.push({0, 0, src});
        minCost[src] = 0;
        
        // Step 1: Build adjacency list for flights
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        while(!pq.empty()){
            int stops = pq.top()[0];
            int cost = pq.top()[1];
            int flight = pq.top()[2];
            pq.pop();

            // Step 2: Process neighbors if stops are within limit
            if(stops <= k){
                for(auto neighbor : adj[flight]){
                    int nFlight = neighbor.first;
                    int price = neighbor.second;

                    // Step 3: Update cost and add to priority queue if better cost is found
                    if(cost + price < minCost[nFlight]){
                        minCost[nFlight] = cost + price;
                        pq.push({stops + 1, minCost[nFlight], nFlight});
                    }
                }
            }
        }

        // Step 4: Return result if reachable, otherwise -1
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};