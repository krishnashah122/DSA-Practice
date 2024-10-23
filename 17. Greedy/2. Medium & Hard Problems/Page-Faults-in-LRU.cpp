// Page Faults in LRU (GFG)
// GFG Link : https://shorturl.at/8SL2p

// Time Complexity : O(n*c)
// Space Complexity : O(c)

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pageFaults = 0;
        vector<int> cache;
        
        for(int i = 0; i < N; i++){
            // Step 1: Check if current page is not in cache (page fault)
            auto it = find(cache.begin(), cache.end(), pages[i]);
            if(it == cache.end()){
                pageFaults++;  // Increment page fault count
                cache.push_back(pages[i]);  // Add new page to cache
                
                // If cache exceeds capacity, remove LRU page
                if(cache.size() > C){
                    cache.erase(cache.begin());
                }
            }else{
                // Step 2: If page found in cache
                cache.erase(it); // Remove page from its current position
                cache.push_back(pages[i]); // Move it to the back (most recently used)
            }
        }
        
        return pageFaults;
    }
};