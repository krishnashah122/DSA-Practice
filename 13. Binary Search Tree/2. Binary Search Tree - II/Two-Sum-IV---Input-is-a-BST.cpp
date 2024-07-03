// Two Sum IV - Input is a BST (Leetcode)
// Leetcode Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    void searchTarget(TreeNode* root, int k, set<int> &s, bool &isFound){
        if(root == NULL) return;

        searchTarget(root->left, k, s, isFound);

        int remaining = k - root->val;
        // Check if remaining part is present in set or not
        if(s.find(remaining) != s.end()){
            // If present, make isFound true and return
            isFound = true;
            return;
        }
        // If remaining part is not present in set, insert current node's value in the set
        s.insert(root->val);

        searchTarget(root->right, k, s, isFound);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        bool isFound = false;
        searchTarget(root, k, s, isFound);
        return isFound;
    }
};