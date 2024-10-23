// N meetings in one room (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Time Complexity : O(n + nLogn)
// Space Complexity : O(n)

class Solution {
  public:
    struct Meeting{
        int startTime;
        int endTime;
    };
    
    // Comparator function to sort meetings by their end time
    bool static comparator(Meeting a, Meeting b){
        return a.endTime < b.endTime;
    }
  
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        // Step 1: Create an array of Meeting structs and populate it with start and end times
        Meeting arr[n];
        for(int i = 0; i < n; i++) {
            arr[i].startTime = start[i];
            arr[i].endTime = end[i];
        }
        
        // Step 2: Sort the array based on end times using the comparator
        sort(arr, arr + n, comparator);
        
        // Step 3: Initialize the number of meetings and track the end time of the last selected meeting
        int meetings = 1;
        int prevEnd = arr[0].endTime;
        
        // Step 4: Iterate through the sorted array and select meetings that start after the last selected meeting ends
        for(int i = 1; i < n; i++) {
            if(arr[i].startTime > prevEnd) {
                meetings++;
                prevEnd = arr[i].endTime;
            }
        }
        
        // Step 5: Return the total number of meetings that can be performed
        return meetings;
    }
};