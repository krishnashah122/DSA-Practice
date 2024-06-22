// Binary Tree Zigzag Level Order Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

// Time Complexity : O(n)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // If root is empty, return empty ans
        if(root == NULL) return ans;

        queue<TreeNode*> q; // To store nodes
        q.push(root);
        bool isZigZag = false; // Flag for zig zag traversal

        // BFS Traversal
        while(!q.empty()){
            int n = q.size();
            vector<int> level;

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // If isZigZag is true, reverse the order of current level
            if(isZigZag) reverse(level.begin(), level.end());
            ans.push_back(level);
            // Toggle isZigZag
            isZigZag = !isZigZag;
        }

        return ans;
    }
};