// Construct Binary Search Tree from Preorder Traversal (Leetcode)
// Leetcode Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode* buildBST(vector<int>& preorder, int &i, int bound){
        // If current index >= preorder's length or the current value exceeds the bound, return NULL
        if(i >= preorder.size() || preorder[i] > bound) return NULL;

        // Create a new TreeNode with the current value
        TreeNode* root = new TreeNode(preorder[i]);
        i++; // Move to the next index of preorder

        // Build left subtree with updated bound set to the current node's value
        root->left = buildBST(preorder, i, root->val);
        // Build right subtree with updated bound set to the current bound
        root->right = buildBST(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        // Start building the BST with the initial bound set to INT_MAX
        return buildBST(preorder, i, INT_MAX);
    }
};