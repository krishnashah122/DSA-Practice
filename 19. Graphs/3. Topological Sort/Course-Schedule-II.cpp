// Course Schedule II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/course-schedule-ii/description/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> topoOrder;

        // Step 1: Build adjacency list and calculate indegree for each course
        for(vector<int> &courses : prerequisites){
            adj[courses[1]].push_back(courses[0]);
            indegree[courses[0]]++;
        }

        // Step 2: Push courses with zero indegree into the queue
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // Step 3: Process the queue using Kahn's Algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // Step 4: Add the course to the topological order
            topoOrder.push_back(node);

            // Step 5: Reduce indegree of neighbors and add to queue if indegree becomes zero
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        // Step 6: If all courses can't be completed, return an empty array
        if(topoOrder.size() != numCourses){
            return {};
        }
        
        // Step 7: Return topological order if all courses can be completed
        return topoOrder;
    }
};