// Asteroid Collision (Leetcode)
// Leetcode Link : https://leetcode.com/problems/asteroid-collision/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int &asteroid : asteroids){
            // If the asteroid is moving to the right
            if(asteroid > 0){
                // Add it to the result vector
                ans.push_back(asteroid);
            }
            // If the asteroid is moving to the left
            else{
                // While there are asteroids in the result vector, the last asteroid is moving to the right,
                // and the last asteroid is smaller than the current asteroid (in absolute value)
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroid)){
                    // Remove the last asteroid from the result vector (it gets destroyed)
                    ans.pop_back();
                }
                
                // If the last asteroid in the result vector is equal in size (in absolute value) to the current asteroid
                if(!ans.empty() && ans.back() == abs(asteroid)){
                    // Both asteroids get destroyed
                    ans.pop_back();
                }
                // If the result vector is empty or the last asteroid is moving to the left
                else if(ans.empty() || ans.back() < 0){
                    // Add the current asteroid to the result vector
                    ans.push_back(asteroid);
                }
            }
        }

        return ans;
    }
};