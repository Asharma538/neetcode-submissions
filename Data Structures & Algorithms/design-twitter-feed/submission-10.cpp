class Twitter {
public:
    vector<set<int>> users;
    vector<vector<pair<int,int>>> tweets;
    int time;

    Twitter() {
        users = vector<set<int>>(101);
        tweets = vector<vector<pair<int,int>>>(101);
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for(auto i : users[userId]){
            for(auto j : tweets[i]) pq.push(j);
        }
        
        for(auto j : tweets[userId]) pq.push(j);

        set<int> f;
        vector<int> feed;
        for(; f.size()<10 and pq.size() ;){
            f.insert(pq.top().second);
            if (f.size() > feed.size()) feed.push_back(pq.top().second);
            pq.pop();
        }
        time++;

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        time++;
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        time++;
        users[followerId].erase(followeeId);
    }
};
