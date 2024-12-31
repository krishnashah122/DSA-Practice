// All Paths From Source to Target (Leetcode)
// Leetcode Link : https://leetcode.com/problems/all-paths-from-source-to-target/description/

// Time Complexity : O(2^V)
// Space Complexity : O(V + E)

class Solution {
public:
    void dfs(vector<vector<int>>& graph, stack<int> &st, vector<int> &path, vector<vector<int>> &paths){
        int node = st.top();
        st.pop();

        // Step 1: If we reach the target node, add the current path to paths
        if(node == graph.size()-1) paths.push_back(path);

        // Step 2: Explore each neighbor of the current node
        for(int neighbor : graph[node]){
            path.push_back(neighbor); // Add the neighbor to the path
            st.push(neighbor); // Push the neighbor onto the stack

            // Step 3: Recursively perform DFS
            dfs(graph, st, path, paths);
            path.pop_back(); // Backtrack
        }

        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        stack<int> st;
        vector<vector<int>> paths;
        vector<int> path;

        // Step 1: Start DFS with the initial node (0)
        st.push(0);
        path.push_back(0);

        dfs(graph, st, path, paths);

        // Step 2: Return all found paths
        return paths;
    }
};