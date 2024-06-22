// Vertical Order Traversal of a Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

// Time Complexity : O(n * Logn * Logn * Logn)
// Space Complexity : O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp; // To store nodes by their vertical and horizontal distances
        queue<pair<TreeNode*, pair<int, int>>> q; // Queue for level order traversal
        q.push({root, {0, 0}});

        while(!q.empty()){
            // Get the front entry of the queue
            auto it = q.front();
            // Remove the front entry of the queue
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mp[x][y].insert(node->val);

            if(node->left){
                // Add left child to the queue with updated distances
                q.push({node->left, {x - 1, y + 1}});
            }

            if(node->right){
                // Add right child to the queue with updated distances
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Iterate over the map sorted by vertical and horizontal distance
        for(auto outer : mp){
            vector<int> column;
            for(auto inner : outer.second){
                column.insert(column.end(), inner.second.begin(), inner.second.end());
            }
            ans.push_back(column);
        }

        return ans;
    }
};