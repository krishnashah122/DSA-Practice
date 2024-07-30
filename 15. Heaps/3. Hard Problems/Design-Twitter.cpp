// Design Twitter (Leetcode)
// Leetcode Link : https://leetcode.com/problems/design-twitter/description/

// Time Complexity :
//      -> postTweets : O(1)
//      -> getNewsFeed : O(users * tweets + kLogk) [where, k is min(users * 10, 10).]
//      -> follow : O(1)
//      -> unfollow : O(1)

// Space Complexity : O(users * tweets)
//      -> postTweets : O(T) [where, T is the no. of tweets.]
//      -> getNewsFeed : O(users * tweets)
//      -> follow : O(U + F) [where, U is the no. of users and F is the no. of follow relations.]
//      -> unfollow : O(U + F) [where, U is the no. of users and F is the no. of follow relations.]

class Twitter {
private:
    // Map to store tweets for each user. The vector contains pairs of tweet's timestamp & tweetId.
    unordered_map<int, vector<pair<int, int>>> userTweets;
    // Map to store the following for each user.
    unordered_map<int, unordered_set<int>> userFollows;
    // Counter to provide a unique timestamp to each tweet.
    int tweetTime;

public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        // Increment tweetTime to ensure the order of tweets.
        userTweets[userId].push_back({++tweetTime, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Set to keep track of current user's following, including the current user.
        unordered_set<int> following = userFollows[userId];
        following.insert(userId);

        // Min-heap to keep the most recent tweets.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> latestTweets;

        // Iterate over each user the current user is following.
        for(int user : following){
            // Iterate over all tweets of the current user.
            for(auto &tweet : userTweets[user]){
                // Add tweet to the heap.
                latestTweets.push(tweet);
                // If the heap size exceeds 10, remove the oldest tweet.
                if(latestTweets.size() > 10){
                    latestTweets.pop();
                }
            }
        }

        vector<int> newsFeed;
        // Extract recent tweet's IDs from the heap and store them in the result vector.
        while(!latestTweets.empty()){
            newsFeed.push_back(latestTweets.top().second);
            latestTweets.pop();
        }

        // Reverse the vector to have the most recent tweets first.
        reverse(newsFeed.begin(), newsFeed.end());

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        // Add followeeId to the list of users that followerId follows.
        userFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Remove followeeId from the list of users that followerId follows.
        userFollows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */