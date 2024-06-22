// Lowest Common Ancestor of a Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// Time Complexity : O(n)
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
        
        // If either p or q is the root, then the root is the LCA
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one of the subtrees returns NULL, meaning p and q are in the other subtree
        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            // If p is found in one subtree and q in the other, root is the LCA
            return root;
        }
    }
};