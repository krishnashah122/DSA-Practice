// Find Eventual Safe States (Leetcode)
// Leetcode Link : https://leetcode.com/problems/find-eventual-safe-states/description/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size(); 
        vector<vector<int>> reverseGraph(V);
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> safeNodes;

        // Step 1: Build the reverse graph and calculate indegrees
        for(int i = 0; i < V; i++){
            for(int neighbor : graph[i]){
                reverseGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        // Step 2: Add nodes with zero indegree to the queue
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // Step 3: Process the queue to find safe nodes
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            // Step 4: Reduce indegree for neighbors and enqueue if it becomes zero
            for(int neighbor : reverseGraph[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Sort the safe nodes
        sort(safeNodes.begin(), safeNodes.end());

        // Step 6: Return the sorted list of safe nodes
        return safeNodes;
    }
};