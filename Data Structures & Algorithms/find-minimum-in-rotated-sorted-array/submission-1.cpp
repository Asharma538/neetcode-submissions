class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]){
            return nums[0];
        }

        int l = 0, r = n-1;
        int miny = nums[r];
        while(l < r){
            int mid = (l+r)/2;
            if (nums[mid] > nums[r]){
                l = mid+1;
            } else {
                r = mid;
            }
            miny = min(miny, nums[mid]);
        }
        miny = min(miny, nums[r]);

        return miny;
    }
};
