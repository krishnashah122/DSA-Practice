// Same Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, the trees are the same at this level
        if(p == NULL && q == NULL) return true;
        
         // If one node is NULL and the other is not, the trees are not the same
        if(p == NULL || q == NULL) return false;

        // If the values of the nodes are different, the trees are not the same
        if(p->val != q->val) return false;

        // Recursively check if the left and right subtrees are the same
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};