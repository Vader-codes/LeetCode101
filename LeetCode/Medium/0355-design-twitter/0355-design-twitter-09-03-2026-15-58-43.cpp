class Twitter {
public:
  int time; // this will repesent the post time 
  unordered_map<int, vector<pair<int, int>>>tweets;
  unordered_map<int, unordered_set<int>>follows;

    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>>allTweets;
        // Include self tweets
        if(tweets.count(userId)){
            allTweets.insert(allTweets.end(), tweets[userId].begin(), tweets[userId].end());
        }
        // include followees
        for(auto f : follows[userId]){
             allTweets.insert(allTweets.end(), tweets[f].begin(), tweets[f].end());
        }
        // sort them 
        sort(allTweets.rbegin(), allTweets.rend());
        vector<int>result;

        // pick top 10
        for(int i=0; i<min(10, (int)allTweets.size()); i++){
            result.push_back(allTweets[i].second);
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followeeId != followerId){
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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