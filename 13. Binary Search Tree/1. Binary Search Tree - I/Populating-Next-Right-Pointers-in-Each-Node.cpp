// Populating Next Right Pointers in Each Node (Leetcode)
// Leetcode Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                Node* node = q.front(); // Get the front node of the queue
                q.pop(); // Pop the front node of the queue

                // If current front of queue is of same level
                if(i + 1 < n){
                    node->next = q.front(); // Assign current front of queue to the current node's next
                }else{
                    // If current front of queue is of another level
                    node->next = NULL; // Assign NULL to the current node's next
                }

                // If left and right child is present, push it into the queue
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return root;
    }
};