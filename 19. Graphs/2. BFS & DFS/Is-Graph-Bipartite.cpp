// Is Graph Bipartite? (Leetcode)
// Leetcode Link : https://leetcode.com/problems/is-graph-bipartite/description/

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, stack<pair<int, int>> &st, vector<int> &colored){
        int node = st.top().first;
        int parentColor = st.top().second;
        st.pop();

        for(int neighbor : graph[node]){
            if(colored[neighbor] == -1){
                // Step 1: Color unvisited neighbor and push it to the stack
                st.push({neighbor, !parentColor});
                colored[neighbor] = !parentColor;
                
                // Step 2: Recursively check for bipartiteness for the neighbor
                if(!checkBipartite(graph, st, colored)){
                    return false; // If the graph is not bipartite, return false
                }
            } else if(colored[neighbor] == colored[node]) {
                // Step 3: If two adjacent nodes have the same color, return false
                return false;
            }
        }

        // Step 4: Return true if all neighbors are valid and graph remains bipartite
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // // 1. BFS Approach
        // int V = graph.size();

        // // Step 1: Initialize color array
        // vector<int> colored(V, -1); // ('-1' -> not colored), ('0' -> color 1) & ('1' -> color 2)
        // queue<pair<int, int>> q;

        // for(int i = 0; i < V; i++){
        //     if(colored[i] == -1){  
        //         // Step 2: Start BFS if node is not yet colored
        //         q.push({i, 0});
        //         colored[i] = 0;
                
        //         while(!q.empty()){
        //             int node = q.front().first;
        //             int parentColor = q.front().second;
        //             q.pop();

        //             for(int neighbor : graph[node]){
        //                 if(colored[neighbor] == -1){  
        //                     // Step 3: Color uncolored neighbors
        //                     q.push({neighbor, !parentColor});
        //                     colored[neighbor] = !parentColor;
        //                 }else if(colored[neighbor] == parentColor){  
        //                     // Step 4: If graph is not bipartite, return false
        //                     return false;
        //                 }
        //             }
        //         }
        //     }
        // }
        
        // // Step 5: Return true if bipartite
        // return true;


        // 2. DFS Approach
        int V = graph.size();
        vector<int> colored(V, -1);
        stack<pair<int, int>> st;

        for(int i = 0; i < V; i++) {
            if(colored[i] == -1) {
                // Step 1: Start DFS for unvisited nodes
                st.push({i, 0});
                colored[i] = 0;
                if(!checkBipartite(graph, st, colored)){
                    // Step 2: Return false if graph is not bipartite
                    return false;
                }
            }
        }

        // Step 3: Return true if the graph is bipartite
        return true;
    }
};