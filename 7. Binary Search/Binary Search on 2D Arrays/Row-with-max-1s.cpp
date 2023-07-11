// Row with max 1s (Code Studio)
// Code Studio Link : https://shorturl.at/ctDIY

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int maxOnes = 0; // stores the max no. of 1 a particular row
    int maxOnesRow = -1; // stores the row no. having max no. of 1

    // iterate for all rows
    for(int i = 0; i < n; i++){ // O(n)
        int low = 0;
        int high = m - 1;

        while(low <= high){ // O(Logm)
            int mid = low + (high - low) / 2;

            if(matrix[i][mid] == 1){
                // if no. of 1's in current row is greater than the maxOnes
                if(m - mid > maxOnes){
                    maxOnes = m - mid; // update the maxOnes with (mid - m)
                    maxOnesRow = i; // update the maxOnesRow with i
                }

                high = mid - 1; // to search in left part
            }
            else{
                low = mid + 1; // to search in right part
            }
        }
    }
    return maxOnesRow;
}