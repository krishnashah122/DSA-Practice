// Construct Binary Tree from Preorder and Inorder Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
        if(start > end) return NULL;

        // Create a new TreeNode with the current value from preorder traversal
        TreeNode* root = new TreeNode(preorder[idx]);
        
        // Find the index of current root value in the inorder traversal
        int i;
        for(i = start; i <= end; i++){
            if(inorder[i] == root->val){
                break;
            }
        }

        // Increament the index of preorder traversal
        idx++;

        // Build the left and the right subtrees
        root->left = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // Index for preorder traversal
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};