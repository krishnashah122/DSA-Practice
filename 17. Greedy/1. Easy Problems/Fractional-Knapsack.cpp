// Fractional Knapsack (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Comparison function to sort items based on value-to-weight ratio
    bool static compareByRatio(Item a, Item b){
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
  
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        // Step 1: Sort the items in decreasing order based on their value-to-weight ratio
        sort(arr, arr + n, compareByRatio);
        
        // Step 2: Initialize variables to keep track of total weight and total value
        int totalWeight = 0;
        double totalValue = 0.0;
        
        // Step 3: Iterate through the sorted items
        for(int i = 0; i < n; i++) {
            // Step 4: If the current item can be fully added to the knapsack, add its weight & value to the totalWeight & totalValue respectively
            if(totalWeight + arr[i].weight <= w) {
                totalWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                // Step 5: If the item cannot be fully added, add the value of the remaining weight that fits in capacity, and break the loop
                int remaining = w - totalWeight;
                totalValue += ((double) arr[i].value / (double) arr[i].weight) * (double) remaining;
                break;
            }
        }
        
        return totalValue;
    }
};