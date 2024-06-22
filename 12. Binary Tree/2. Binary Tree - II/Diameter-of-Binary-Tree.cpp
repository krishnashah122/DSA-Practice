// Diameter of Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int getDiameter(TreeNode* root, int &diameter){
        if(root == NULL) return 0;

        int leftHeight = getDiameter(root->left, diameter);
        int rightHeight = getDiameter(root->right, diameter);
        diameter = max(diameter, (leftHeight + rightHeight));
        return 1 + max(leftHeight, rightHeight); 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getDiameter(root, diameter);
        return diameter;
    }
};