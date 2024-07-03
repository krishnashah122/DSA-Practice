// Predecessor and Successor (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

// Time Complexity : O(h) where, h is the height of the binary search tree.
// Space Complexity : O(1)

/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        
        Node* temp = root;
        while(temp){
            // If current node's value is smaller than key value
            if(temp->key < key){
                pre = temp; // Update pre with current node
                temp = temp->right; // Move to the right child
            }else{
                // Otherwise, move to the left child
                temp = temp->left;
            }
        }
        
        temp = root;
        while(temp){
            // If current node's value is greater than key value
            if(temp->key > key){
                suc = temp; // Update suc with current node
                temp = temp->left; // Move to the left child
            }else{
                // Otherwise, move to the right child
                temp = temp->right;
            }
        }
    }
};