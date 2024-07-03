// Ceil in BST (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Time Complexity : O(h) where, h is the height of the BST.
// Space Complexity : O(1)

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ans = -1;
    Node* temp = root;
    
    while(temp){
        if(temp->data == input){
            ans = temp->data; // Update the ans
            return ans; // Immediately return ans
        }else if(input < temp->data){
            ans = temp->data; // Update the ans
            temp = temp->left; // Move to the left to find the smaller ceil value
        }else{
            temp = temp->right; // Move to the right to find the larger value that is greater than or equla to input
        }
    }
    
    return ans;
}