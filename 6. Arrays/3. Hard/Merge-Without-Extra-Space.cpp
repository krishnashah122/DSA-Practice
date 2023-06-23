// Merge Without Extra Space (GFG)
// GFG Link : https://bit.ly/3zRzmAo

// Approach : Gap Method
// Time Complexity : O(Log(n+m) * (n+m))
// Space Complexity : O(1)

class Solution{
    public:
    
        // Function to swap
        void swapIfGreater(long long arr1[], long long arr2[], int index1, int index2){
            if(arr1[index1] > arr2[index2]){
                swap(arr1[index1], arr2[index2]);
            }
        }
    
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int len = (n + m);
            int gap = (len / 2) + (len % 2);
            
            while(gap > 0){ // O(log(n+m))
                int left = 0;
                int right = left + gap;
                
                while(right < len){ // O(n+m)
                    // left in arr1[] and right in arr2[]
                    if(left < n && right >= n){
                        swapIfGreater(arr1, arr2, left, right - n);
                    }
                    // left and right both are in arr2[]
                    else if(left >= n){
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    // left and right both are in arr1[]
                    else{
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    left++;
                    right++;
                }
                
                // break if gap == 1 iteration is completed
                if(gap == 1) break;
                
                // calculate new gap
                gap = (gap / 2) + (gap % 2);
            }
        } 
};