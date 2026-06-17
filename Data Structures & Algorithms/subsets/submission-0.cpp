class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets(1<<n);
        for(int i=0; i < 1<<n ; i++){
            int j = i;
            int idx = 0;
            while(j){
                if (j&1){
                    subsets[i].push_back(nums[idx]);
                }
                j/=2;
                idx++;
            }
        }
        return subsets;
    }
};
