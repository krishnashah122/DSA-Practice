// Job Sequencing Problem (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Time Complexity : O(n^2 + nLogn)
// Space Complexity : O(n)

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    // Comparator function to sort jobs based on profit
    bool static comparator(Job a, Job b){
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // Step 1: Sort jobs in descending order of profit
        sort(arr, arr+n, comparator);
        
        int mp[n+1] = {0}; // Array hashmap to track of free time slots
        int jobDone = 0; // Jobs done counter
        int maxProfit = 0; // To store the max profit
        
        // Step 2: Iterate through all jobs
        for(int i = 0; i < n; i++){
            // Step 3: Find a free slot for this job
            for(int j = arr[i].dead; j > 0; j--){
                // Step 4: If the slot is free, increment jobDone, update maxProfit, assign jobID to mp[j] and then exit loop
                if(mp[j] == 0){
                    jobDone++;
                    maxProfit += arr[i].profit;
                    mp[j] = arr[i].id;
                    break;
                }
            }
        }
        
        vector<int> ans = {jobDone, maxProfit};
        
        return ans;
    } 
};