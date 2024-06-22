// Symmetric Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/symmetric-tree/description/

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
    bool checkSymmetric(TreeNode* leftRoot, TreeNode* rightRoot){
        // If both root are NULL, then it is symmetric
        // If any one is NULL, then it is not symmetric
        if(leftRoot == NULL || rightRoot == NULL){
            return leftRoot == rightRoot;
        }

        // Check if both root's value are same & its left and right subtrees are symmetric or not
        return (leftRoot->val == rightRoot->val)
        && checkSymmetric(leftRoot->left, rightRoot->right)
        && checkSymmetric(leftRoot->right, rightRoot->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true; // If root is NULL, then it is symmetric

        // Check if its left and right subtrees are symmetric or not
        return checkSymmetric(root->left, root->right);
    }
};