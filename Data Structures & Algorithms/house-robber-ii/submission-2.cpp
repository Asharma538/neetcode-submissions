class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()<=3){
            int mx = 0;
            for(auto i : nums) mx = max(i,mx);
            return mx;
        }

        vector<int> org(nums);

        nums[nums.size()-1] = 0;
        nums[2] += nums[0];
        for(int i = 3 ; i < nums.size() ; i++){
            nums[i] += max(nums[i-3], nums[i-2]);
        }
        int mx = max(nums[nums.size()-1], nums[nums.size()-2]);

        nums = org;
        nums[0] = 0;
        for(int i = 3 ; i < nums.size() ; i++){
            nums[i] += max(nums[i-3], nums[i-2]);
        }
        mx = max(nums[nums.size()-1],mx);
        mx = max(nums[nums.size()-2],mx);

        return mx;
    }
};








