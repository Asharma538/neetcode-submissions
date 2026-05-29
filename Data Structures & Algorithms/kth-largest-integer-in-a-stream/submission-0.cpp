class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for(auto i : nums) pq.push(i);
        while(pq.size() > k){
            // cout<<pq.top()<<' ';
            pq.pop();
        }
        // cout<<'\n';
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > s){
            // cout<<pq.top()<<' ';
            pq.pop();
        }
        return pq.top();
    }
};
