// Union of Two Sorted Arrays (GFG)

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n+m)
// Space Complexity :O(n+m)

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector <int> ans;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(arr1[i] <= arr2[j]){
                if(ans.size() == 0 || ans.back() != arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            else if(arr2[j] <= arr1[i]){
                if(ans.size() == 0 || ans.back() != arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        // If some elements of arr1[] is left-out
        while(i < n){
            if(ans.size() == 0 || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        
        // If some elements of arr2[] is left-out
        while(j < m){
            if(ans.size() == 0 || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
        
        return ans;
    }
};