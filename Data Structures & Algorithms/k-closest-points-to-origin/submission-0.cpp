class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;
        for(auto i : points){
            pq.push({i[0]*i[0] + i[1]*i[1], {i[0],i[1]}});
        }
        vector<vector<int>> ans(k, vector<int>(2));
        for(int i = 0 ; i < k ; i++){
            ans[i][0] = pq.top().second.first;
            ans[i][1] = pq.top().second.second;
            pq.pop();
        }
        return ans;
    }
};
