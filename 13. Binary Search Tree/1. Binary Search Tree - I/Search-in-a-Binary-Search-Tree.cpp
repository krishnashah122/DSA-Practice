// Search in a Binary Search Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        // If root is NULL, return root
        if(root == NULL) return root;

        // If root's value is equal to val, return root
        if(root->val == val){
            return root;
        }else if(root->val > val){
            // If root's value is greater than val, search in left subtree
            return searchBST(root->left, val);
        }else{
            // If root's value is smaller than val, search in right subtree
            return searchBST(root->right, val);
        }
    }
};