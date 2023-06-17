// Make Zeroes (GFG)
// GFG Link : https://bit.ly/3SVaSig

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp = matrix; // copy of matrix
        
        // traverse temp to perform checks and modify matrix accordingly
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j] == 0){
                    // for upper neighbour element
                    if(i-1 >= 0){
                        matrix[i][j] += temp[i-1][j];
                        matrix[i-1][j] = 0;
                    }
                    
                    // for right neighbour element
                    if(j+1 < m){
                        matrix[i][j] += temp[i][j+1];
                        matrix[i][j+1] = 0;
                    }
                    
                    // for lower neighbour element
                    if(i+1 < n){
                        matrix[i][j] += temp[i+1][j];
                        matrix[i+1][j] = 0;
                    }
                    
                    // for left neighbour element
                    if(j-1 >= 0){
                        matrix[i][j] += temp[i][j-1];
                        matrix[i][j-1] = 0;
                    }
                }
            }
        }
    }
};