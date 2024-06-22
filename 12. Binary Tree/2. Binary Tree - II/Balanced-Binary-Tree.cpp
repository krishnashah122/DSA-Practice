// Balanced Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/balanced-binary-tree/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

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
    int checkBalanced(TreeNode* root, bool &isBalanced){
        if(root == NULL) return 0;

        int lh = checkBalanced(root->left, isBalanced);
        int rh = checkBalanced(root->right, isBalanced);
        // If depth of 2 subtrees is more than 1, make isBalanced false
        if(abs(lh - rh) > 1) isBalanced = false;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        checkBalanced(root, isBalanced);
        return isBalanced;
    }
};