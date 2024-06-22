// Boundary Traversal of binary tree (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Time Complexity : O(n)
// Space Complexity : O(n)

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // Function to check whether root is a leaf node or not
    bool isLeaf(Node *root){
        return (!root->left && !root->right);
    }
    
    // Function to traverse the left boundary
    void leftBoundary(Node *root, vector<int> &ans){
        Node *node = root->left;
        
        while(node){
            if(!isLeaf(node)) ans.push_back(node->data);
            if(node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    
    // Function to traverse the leaf boundary
    void leafBoundary(Node *root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        if(root->left) leafBoundary(root->left, ans);
        if(root->right) leafBoundary(root->right, ans);
    }
    
    // Function to traverse the right boundary
    void rightBoundary(Node *root, vector<int> &ans){
        Node *node = root->right;
        vector<int> temp;
        
        while(node){
            if(!isLeaf(node)) temp.push_back(node->data);
            if(node->right)
                node = node->right;
            else
                node = node->left;
        }
        
        // Add temp elements in ans in reverse order
        for(int i = temp.size() - 1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        
        // Add root node in ans
        if(!isLeaf(root)) ans.push_back(root->data);
        
        // Left boundary traversal
        leftBoundary(root, ans);
        // Leaf boundary traversal
        leafBoundary(root, ans);
        // Right boundary traversal
        rightBoundary(root, ans);
        
        return ans;
    }
};