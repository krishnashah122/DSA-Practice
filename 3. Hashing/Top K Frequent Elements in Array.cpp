// Top K Frequent Elements in Array (GFG)

// Time Complexity for map : O(Logn)
// Time Complexity for unordered_map : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int, int>mpp;
        vector<int>ans;
        
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>>q;
        for(auto i : mpp){
            q.push({i.second, i.first});
        }
        
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}

