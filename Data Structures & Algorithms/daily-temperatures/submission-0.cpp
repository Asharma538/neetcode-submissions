class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmps) {
        stack<int> s;
        vector<int> ans(tmps.size(),0);
        for(int i = 0 ; i < tmps.size() ; i++){
            while (s.size() && tmps[i] > tmps[s.top()]){
                    ans[s.top()] = i - s.top();
                    s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
