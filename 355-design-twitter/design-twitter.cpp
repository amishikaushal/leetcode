class Twitter {
private: 
    int time;
    unordered_map<int , unordered_set<int>> follows;
    unordered_map<int , vector<pair<int , int>>> tweets;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int , int>> pq;
        follows[userId].insert(userId);

        for(auto &followee : follows[userId]){
            for(auto & t : tweets[followee]){
                pq.push(t);
            }

        }


        vector<int> ans;
        int cnt = 0;

        while(!pq.empty() && cnt < 10){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follows[followerId].erase(followeeId);
        }
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