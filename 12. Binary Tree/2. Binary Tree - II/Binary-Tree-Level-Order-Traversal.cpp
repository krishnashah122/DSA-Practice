// Binary Tree Level Order Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // If root is NULL, return the empty ans
        if(root == NULL) return ans;

        queue<TreeNode*> q; // To store the node of the tree
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level;

            // Traverse through the queue
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); // Get the front node of the queue
                q.pop(); // Pop the front node from the queue

                level.push_back(node->val);

                // If popped node has left child
                if(node->left){
                    q.push(node->left); // Push the left child in the queue
                }

                // If popped node has right child
                if(node->right){
                    q.push(node->right); // Push the right child in the queue
                }
            }
            ans.push_back(level); // Add the level vector in the ans
        }

        return ans;
    }
};