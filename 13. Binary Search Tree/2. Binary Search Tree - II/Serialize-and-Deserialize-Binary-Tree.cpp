// Serialize and Deserialize Binary Tree (Leetcode)
// Leetcode Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializeStr = "";
        queue<TreeNode*> q;
        
        // If root is not NULL, push it into the queue
        if(root) q.push(root);

        // Perform BFS traversal
        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                
                // If node is not NULL
                if(node){
                    // Push its left & right child to the queue
                    q.push(node->left);
                    q.push(node->right);
                    // Add node's value to the serializeStr as a string
                    serializeStr += to_string(node->val) + ",";
                }else{
                    // If node is NULL, add "#" to the serializeStr
                    serializeStr += "#,";
                }
            }
        }

        return serializeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        queue<TreeNode*> q;
        stringstream s(data);
        string str;

        // Read the first value & create the root node
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        // Push the root node to the queue
        q.push(root);

        // Perform BFS traversal
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // Read the left child value
            getline(s, str, ',');
            // If the value is "#", left child is NULL
            if(str == "#"){
                node->left = NULL;
            }else{
                // Otherwise, create left child node and push it into the queue
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Read the right child value
            getline(s, str, ',');
            // If the value is "#", right child is NULL
            if(str == "#"){
                node->right = NULL;
            }else{
                // Otherwise, create right child node and push it into the queue
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));