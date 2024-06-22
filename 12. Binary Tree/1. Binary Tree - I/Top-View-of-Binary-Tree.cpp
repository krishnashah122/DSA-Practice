// Top View of Binary Tree (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Time Complexity : O(n)
// Space Complexity : O(n)

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, int> mp; // To store line --> node->data
        queue<pair<Node*, int>> q; // To store node --> line
        q.push({root, 0});
        
        while(!q.empty()){
            // Get the front element of the queue
            auto it = q.front();
            // Pop the front element of the queue
            q.pop();
            Node *node = it.first;
            int line = it.second;
            
            // If key is not in the map, make a entry of the current node->data for the line
            auto key = mp.find(line);
            if(key == mp.end()){
                mp[line] = node->data;
            }
            
            // If the node at front of queue has left child, push it by decreamenting line by 1
            if(node->left != NULL){
                q.push({node->left, line - 1});
            }
            
            // If the node at front of queue has right child, push it by increamenting line by 1
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        
        // Add each node's data to the ans vector
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};