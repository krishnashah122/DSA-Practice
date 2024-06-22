// Binary Tree Maximum Path Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int getMaxPathSum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        // Recursively get the max path sums for left and right subtrees, treating negative sums as 0
        int leftSum = max(0, getMaxPathSum(root->left, maxi));
        int rightSum = max(0, getMaxPathSum(root->right, maxi));

        // Update the max path sum
        maxi = max(maxi, leftSum + rightSum + root->val);
        // Return the max sum of paths ending at the current node
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        getMaxPathSum(root, maxi);
        return maxi;
    }
};