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
        typedef pair<int,int>p;
        priority_queue<p, vector<p>, greater<p>>pq;
        // Include self tweets
        if(tweets.count(userId)){
             for(auto &t : tweets[userId]){
                pq.push(t);
                if(pq.size() > 10)pq.pop();
             }
        }
       // user's followees tweets

       for(auto &person : follows[userId]){
            // include this person's tweets
            for(auto &t : tweets[person]){
                pq.push(t);
                if(pq.size() > 10)pq.pop();
            }
       }
       vector<int>feed;
       while(!pq.empty()){
         feed.push_back(pq.top().second);
         pq.pop();
       }
       reverse(feed.begin(), feed.end());
       return feed;
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