// Root to Leaf Paths (GFG)
// GFG Link : https://shorturl.at/L9JtP

// Time Complexity : O(n)
// Space Complexity : O(n)

/*

Definition for Binary Tree Node
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

class Solution {
  public:
    void getPath(Node* root, vector<int> &path, vector<vector<int>> &ans){
        if(root == NULL) return;
        
        // Add the current node to the path
        path.push_back(root->data);
        
        // If the current node is the leaf node, add the current path to the ans
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }else{
            // Else continue to explore the left and the right children
            getPath(root->left, path, ans);
            getPath(root->right, path, ans);
        }
        
        // Backtrack : Remove the current node from the path
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> path;
        vector<vector<int>> ans;
        getPath(root, path, ans);
        return ans;
    }