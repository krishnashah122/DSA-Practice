// Floor in BST (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/floor-in-bst/1

// Time Complexity : O(h) where, h is the height of the BST.
// Space Complexity : O(1)

class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        Node* temp = root;
        
        while(temp){
            if(temp->data == x){
                ans = temp->data; // Update ans
                return ans; // Immediately return ans
            }else if(x > temp->data){
                ans = temp->data; // Update ans
                temp = temp->right; // Move to right child to find the larger floor value
            }else{
                temp = temp->left; // Move to left child to find the smaller value that is less than or equal to x
            }
        }
        
        return ans;
    }
};