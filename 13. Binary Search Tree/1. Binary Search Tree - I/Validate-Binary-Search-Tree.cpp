// Validate Binary Search Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool checkValid(TreeNode* root, long long lb, long long ub){
        if(root == NULL) return true;

        // If current node's value is greater than lower bound or smaller than upper bound
        if(root->val > lb && root->val < ub){
            // Check for left and right subtrees
            return checkValid(root->left, lb, root->val) && checkValid(root->right, root->val, ub);
        }else{
            // Otherwise, return false
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return checkValid(root, LLONG_MIN, LLONG_MAX); // LLONG_MIN and LLONG_MAX to avoid overflow
    }
};