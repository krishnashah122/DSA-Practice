// Lowest Common Ancestor of a Binary Search Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// Time Complexity : O(h) where, h is the height of the binary search tree.
// Space Complexity : O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        // If either p or q is the root, root is the LCA
        if(root == p || root == q) return root;
        
        // If p->val is smaller than root->val and q->val is greater than root->val, return root
        // OR, If p->val greater than root->val and q->val is smaller than root->val, return root
        if(p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val){
            return root;
        }else if(p->val < root->val && q->val < root->val){
            // If root->val is smaller than p->val and q->val, find LCA in left subtree
            return lowestCommonAncestor(root->left, p, q);
        }else{
            // If root->val is greater than p->val and q->val, find LCA in right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};