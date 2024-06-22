// Check for Children Sum Property in a Binary Tree (GFG)
// GFG Link : https://shorturl.at/aA3xG

// Time Complexity : O(n)
// Space Complexity : O(1)

/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == NULL) return 1;
     
     // If root is a leaf node, return 1
     if(root->left == NULL && root->right == NULL){
         return 1;
     }
     
     // If its child is not NULL, assign its value, otherwise, assign 0
     int left = root->left? root->left->data : 0;
     int right = root->right? root->right->data : 0;
     
     // If sum of value of left and right child node is equal to the value of root node
     if(root->data == left + right){
         // Check for the left and right child node
         return isSumProperty(root->left) && isSumProperty(root->right);
     }else{
         // If sum of value of left and right child node is not equal to the value of root node, return 0
         return 0;
     }
    }
};