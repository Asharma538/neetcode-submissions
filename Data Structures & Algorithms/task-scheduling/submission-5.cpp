class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26]={0};
        for(auto i : tasks) arr[i-'A']++;

        priority_queue<int> maxHeap;
        for(auto i : arr) if(i>0) maxHeap.push(i);

        int time = 0;
        queue<pair<int,int>> q;
        while (maxHeap.size() or q.size()){
            // cout<<maxHeap.size()<<' '<<q.size()<<'\n';
            time++;
            if (maxHeap.size()){
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt){
                    q.push({cnt, time + n});
                }
            }
            if (q.size() and q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
