class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> la(n);
        stack<int> s;

        for(int i = 0 ; i < n ; i++){
            while(s.size() and h[s.top()]>=h[i]){
                s.pop();
            }
            if (s.size()) la[i] = (i-s.top())*h[i];
            else la[i] = (i+1)*h[i];
            s.push(i);
        }
        while(s.size()) s.pop();

        vector<int> ra(n);
        for(int i = n-1 ; i >= 0 ; i--){
            while(s.size() and h[s.top()]>=h[i]){
                s.pop();
            }
            if (s.size()) ra[i] = (s.top() - i)*h[i];
            else ra[i] = (n - i)*h[i];
            s.push(i);
        }

        for(auto i : la) cout<<i<<' '; cout<<'\n';
        for(auto i : ra) cout<<i<<' '; cout<<'\n';
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans=max(ans,la[i]+ra[i]-h[i]);
        }
        return ans;
    }
};
