// Binary Tree Preorder Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

        // Add the current node's value to the ans
        ans.push_back(root->val);
        // Traverse the left child nodes
        helper(root->left, ans);
        // Traverse the right child nodes
        helper(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};