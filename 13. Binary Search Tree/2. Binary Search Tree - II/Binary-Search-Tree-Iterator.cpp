// Binary Search Tree Iterator (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-search-tree-iterator/description/

// Time Complexity : O(1)
// Space Complexity : O(h) where, h is the height of the BST.

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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        // Push all the left children of the root into the stack
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();

        // If node has right child, push all nodes of its right child
        if(node->right) pushAll(node->right);

        return node->val;
    }
    
    bool hasNext() {
        // Return true if the stack is not empty, otherwise return false
        return !s.empty();
    }

private:
    // Function to push all the left child into the stack
    void pushAll(TreeNode* root){
        TreeNode* node = root;
        while(node){
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */