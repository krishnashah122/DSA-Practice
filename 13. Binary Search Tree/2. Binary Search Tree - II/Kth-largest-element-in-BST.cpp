// Kth largest element in BST (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// Time Complexity : O(n)
// Space Complexity : O(1)

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void getKthLargest(Node *root, int K, int &count, int &kthLarge){
        if(root == NULL || count >= K) return;
        
        getKthLargest(root->right, K, count, kthLarge);
        
        count++;
        // If the current node is the kth largest, store it in kthLarge and return
        if(count == K){
            kthLarge = root->data;
            return;
        }
        
        getKthLargest(root->left, K, count, kthLarge);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int count = 0;
        int kthLarge = INT_MIN;
        getKthLargest(root, K, count, kthLarge);
        return kthLarge;
    }
};