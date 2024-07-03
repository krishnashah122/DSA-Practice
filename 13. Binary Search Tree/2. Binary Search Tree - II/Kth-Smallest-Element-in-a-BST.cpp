// Kth Smallest Element in a BST (Leetcode)
// Leetcode Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void getKthSmallest(TreeNode* root, int k, int &count, int &kthSmall){
        if(root == NULL || count >= k) return;

        getKthSmallest(root->left, k, count, kthSmall);

        count++;
        // If current node is the kth smallest, store it in kthSmall and return
        if(count == k){
            kthSmall = root->val;
            return;
        }

        getKthSmallest(root->right, k, count, kthSmall);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int kthSmall = INT_MIN;
        getKthSmallest(root, k, count, kthSmall);
        return kthSmall;
    }
};