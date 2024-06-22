// Bottom View of Binary Tree (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int, int> mp; // To store line --> node->data
        queue<pair<Node*, int>> q; // To store node --> line
        q.push({root, 0});
        
        while(!q.empty()){
            // Get the front entry of the queue
            auto it = q.front();
            // Pop the front entry of the queue
            q.pop();
            Node *node = it.first;
            int line = it.second;
            // Update the map with current node->data for the line
            mp[line] = node->data;
            
            // If node at front of queue has left child, push it by decreamenting line by 1
            if(node->left != NULL){
                q.push({node->left, line - 1});
            }
            
            // If node at front of queue has right child, push it by increamenting line by 1
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        
        // Add each node's data to the ans vector
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};