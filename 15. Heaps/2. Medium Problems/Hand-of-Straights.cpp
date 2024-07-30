// Hand of Straights (Leetcode)
// Leetcode Link : https://leetcode.com/problems/hand-of-straights/description/

// Time Complexity : O(nLogn + n*k) where, k is the group size.
// Space Complexity : O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        map<int, int> mp;

        // Populate the map with the frequency of each card
        for(int &num : hand){
            mp[num]++;
        }
        
        // Populate the minHeap with pairs of card values and their frequencies
        for(auto &pair : mp){
            minHeap.push(pair);
        }

        // Process cards while the minHeap is not empty
        while(!minHeap.empty()){
            vector<pair<int, int>> temp;

            // Form a group of consecutive cards of size 'groupSize'
            for(int i = 1; i <= groupSize; i++){
                if(!minHeap.empty()){
                    pair<int,int> pair = minHeap.top();
                    minHeap.pop();
                    pair.second--; // Decrement the frequency of this card
                    temp.push_back(pair); // Add this card to the temp vector
                }
            }
            
            // If the size of formed group is not equal to the groupSize, return false
            if(temp.size() != groupSize) return false;
            
            // Check if the cards in the temp vector form a consecutive sequence
            int card = temp[0].first;
            for(int i = 0; i < temp.size(); i++){
                // If cards are not consecutive, return false
                if(card != temp[i].first){
                    return false;
                }
                card++; // Move to the next expected card value
            }

            // Reinsert those cards in minHeap whose frequency is greater than 0
            for(auto &pair : temp){
                if(pair.second > 0) minHeap.push(pair);
            }
        }

        return true;
    }
};