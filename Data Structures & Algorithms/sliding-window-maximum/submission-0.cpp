class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> mxs;
        int n = nums.size();

        multiset<int> ms;
        for(int i=0; i<k; i++) ms.insert(nums[i]);
        mxs.push_back(*(--ms.end()));

        for(int i=k; i<n; i++){
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            mxs.push_back(*(--ms.end()));
        }

        return mxs;
    }
};
