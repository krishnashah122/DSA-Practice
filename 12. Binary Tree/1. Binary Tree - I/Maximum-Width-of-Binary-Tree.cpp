// Maximum Width of Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    typedef unsigned long long ll; // Using long long to avoid overflow
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q; // To store node and its index
        q.push({root, 0});
        ll maxWidth = 0;

        while(!q.empty()){
            int n = q.size();
            ll start = q.front().second; // Index of node present at the front of queue
            ll end = q.back().second; // Index of node present at the back of queue
            ll width = end - start + 1;
            maxWidth = max(maxWidth, width); // Update the maxWidth
            
            // Traverse through queue
            for(int i = 0; i < n; i++){
                // Get the node and its index present at the front of queue
                TreeNode* node = q.front().first;
                ll indx = q.front().second;
                q.pop(); // Pop the front entry of queue

                // Push the left and the right child of the node (if any) in queue
                if(node->left) q.push({node->left, (2 * indx + 1)});
                if(node->right) q.push({node->right, (2 * indx + 2)});
            }
        }

        return maxWidth;
    }
};