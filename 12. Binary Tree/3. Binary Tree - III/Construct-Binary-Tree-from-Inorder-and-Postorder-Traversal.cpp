// Construct Binary Tree from Inorder and Postorder Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* solve(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd){
        if(iStart > iEnd || pStart > pEnd) return NULL;

        // Create a new TreeNode with the current node value of postorder traversal
        TreeNode* root = new TreeNode(postorder[pEnd]);
        
        // Find the index of current root value in inorder traversal
        int i;
        for(i = iStart; i <= iEnd; i++){
            if(inorder[i] == root->val){
                break;
            }
        }

        // No. of elements remaining in the left side of the current root node
        int numsLeft = i - iStart;

        // Build the left and the right subtrees
        root->left = solve(inorder, iStart, i-1, postorder, pStart, pStart + numsLeft - 1);
        root->right = solve(inorder, i + 1, iEnd, postorder, pStart + numsLeft, pEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(inorder, 0, n-1, postorder, 0, n-1);
    }
};