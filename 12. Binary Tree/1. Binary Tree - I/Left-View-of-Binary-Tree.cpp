// Left View of Binary Tree (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Time Complexity : O(n)
// Space Complexity : O(h) where, h is the height of the tree.

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void helper(Node *root, int level, vector<int> &ans){
    if(root == NULL) return;
    
    // If the level == ans.size(), it means we are visiting this level for the first time
    if(level == ans.size()){
        // Add the current node's value in the ans
        ans.push_back(root->data);
    }
    
    // Traverse the left child node with the next level
    helper(root->left, level + 1, ans);
    // Traverse the right child node with the next level
    helper(root->right, level + 1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   helper(root, 0, ans);
   return ans;
}