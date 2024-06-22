// Binary Tree Postorder Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    void helper(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        // Traverse the left child nodes
        helper(root->left, ans);
        // Traverse the right child nodes
        helper(root->right, ans);
        // Add the current node's value to the ans
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};