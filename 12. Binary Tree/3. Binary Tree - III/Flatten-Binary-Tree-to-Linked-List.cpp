// Flatten Binary Tree to Linked List (Leetcode)
// Leetcode Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            // If curr node has left child
            if(curr->left){
                TreeNode* pre = curr->left;

                // Find the rightmost child of left subtree
                while(pre->right) pre = pre->right;
                // Connect the right of rightmost node of left subtree to the right child of curr node
                pre->right = curr->right;
                // Connect the curr node right to the curr node left
                curr->right = curr->left;
                // Assign NULL to the curr node left
                curr->left = NULL;
            }
            // Move curr pointer to its right child node
            curr = curr->right;
        }
    }
};