// Merge k Sorted Lists (Leetcode)
// Leetcode Link : https://leetcode.com/problems/merge-k-sorted-lists/description/

// Time Complexity : O(n * k * Logk)
// Space Complexity : O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to keep track of the smallest elements among the k lists
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > minHeap;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        // Insert the head node of each list into the min-heap
        for(ListNode* list : lists){
            if(list){
                minHeap.push({list->val, list});
            }
        }

        // Extract the smallest element from the heap and build the merged list
        while(!minHeap.empty()){
            pair<int, ListNode*> mini = minHeap.top();
            ListNode* node = mini.second; // Extract the node from the pair
            minHeap.pop();
            temp->next = node; // Add this node to the merged list
            temp = temp->next;

            // If the extracted node has a next node, insert it into the heap
            if(node->next) minHeap.push({node->next->val, node->next});
        }

        return dummy->next;
    }
};