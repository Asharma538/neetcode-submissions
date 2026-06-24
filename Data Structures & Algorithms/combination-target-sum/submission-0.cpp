class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target, int idx=0) {
        if (target < 0) return {};
        vector<vector<int>> v;
        for(int i = idx ; i < nums.size() ; i++){
            if (nums[i] == target){
                v.push_back({nums[i]});
                continue;
            }
            vector<vector<int>> res = combinationSum(nums, target - nums[i], i);
            for(auto j : res){
                vector<int> vr;
                vr.push_back(nums[i]);
                for(auto k : j) vr.push_back(k);
                v.push_back(vr);
            }
        }
        return v;
    }
};
