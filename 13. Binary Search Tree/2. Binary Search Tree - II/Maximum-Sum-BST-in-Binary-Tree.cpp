// Maximum Sum BST in Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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
class NodeValue {
public:
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
public:
    int maxi = INT_MIN;
    NodeValue findMaxSumBST(TreeNode* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // Recursively get values from the left and right subtrees
        NodeValue left = findMaxSumBST(root->left);
        NodeValue right = findMaxSumBST(root->right);

        // Check if the current tree is a valid BST
        if(left.maxNode < root->val && right.minNode > root->val){
            // Update the maxi with the maximum sum found so far
            maxi = max(maxi, left.maxSum + root->val + right.maxSum);
            // If valid, calculate the new minNode, maxNode, and maxSum
            return NodeValue(min(left.minNode, root->val), max(right.maxNode, root->val), left.maxSum + root->val + right.maxSum);
        }

        // If not a valid BST, return an invalid NodeValue with the max sum found so far
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

    int maxSumBST(TreeNode* root) {
        findMaxSumBST(root);
        return (maxi < 0) ? 0 : maxi;
    }
};