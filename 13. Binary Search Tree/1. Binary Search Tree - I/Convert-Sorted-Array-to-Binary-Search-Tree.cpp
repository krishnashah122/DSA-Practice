// Convert Sorted Array to Binary Search Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    TreeNode* buildBST(vector<int>& nums, int low, int high){
        // If low is greater than high, return NULL
        if(low > high) return NULL;

        int mid = (low + high) / 2; // Find the root node's value
        
        // Create root node
        TreeNode* root = new TreeNode(nums[mid]);
        // Build the left subtree
        root->left = buildBST(nums, low, mid - 1);
        // Build the right subtree
        root->right = buildBST(nums, mid + 1, high);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        return buildBST(nums, low, high);
    }
};