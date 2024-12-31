// Course Schedule (Leetcode)
// Leetcode Link : https://leetcode.com/problems/course-schedule/description/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int count = 0;

        // Step 1: Build adjacency list and calculate indegree for each course
        for(vector<int> &courses : prerequisites){
            adj[courses[1]].push_back(courses[0]);
            indegree[courses[0]]++;
        }

        // Step 2: Push courses with 0 indegree into the queue
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // Step 3: Process the queue using BFS (Kahn's Algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            // Step 4: Reduce indegree of neighbors and add to queue if indegree becomes zero
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Return true if all courses can be completed; otherwise, return false
        return count == numCourses;
    }
};