// Intersection of Two Sorted Arrays (Code Studio)
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n+m) [It is possible when i and the very next time j moves and it continues so on.]
// Space Complexity : O(1)

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> ans;
    int j = 0, i = 0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            // Increase the index of arr1[]
            i++;
        }
        else{
            // Increase the index of arr2[]
            j++;
        }
    }
    return ans;
}