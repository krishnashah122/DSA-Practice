// Task Scheduler (Leetcode)
// Leetcode Link : https://leetcode.com/problems/task-scheduler/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        priority_queue<int> maxHeap;
        int time = 0;

        // Count the frequency of each task
        for(char &ch : tasks){
            mp[ch - 'A']++;
        }

        // Push all non-zero frequencies into the max heap
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0) maxHeap.push(mp[i]);
        }

        // Process tasks
        while(!maxHeap.empty()){
            vector<int> temp;

            // Process up to (n + 1) tasks in one cycle
            for(int i = 1; i <= (n+1); i++){
                if(!maxHeap.empty()){
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    freq--; // Decrease its frequency
                    temp.push_back(freq); // Add the updated frequency to temp
                }
            }

            // Push the updated frequencies back into the max heap
            for(int &f : temp){
                if(f > 0) maxHeap.push(f);
            }

            // If max heap is empty, we only used as many cycles as we had tasks
            if(maxHeap.empty()){
                time += temp.size();
            }else{
                // Otherwise, we used a full (n + 1) cycles time frame
                time += (n+1);
            }
        }

        return time;
    }
};