// Graph and Vertices (GFG)
// GFG Link : https://shorturl.at/ijQGw

// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
  public:
    long long count(int n) {
        // your code here
        long long edges = (n*(n-1))/2; // No. of Edges
        long long graphs = pow(2, edges); // Total no. of graphs
        return graphs;
    }
};