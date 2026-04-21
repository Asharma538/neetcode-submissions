class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;

        int mid;
        while(l < r){
            mid = (l+r)/2;
            if (nums[mid] > nums[r]){
                l = mid+1;
            } else {
                r = mid;
            }
        }

        mid = r;
        int l1 = 0, r1 = mid, l2 = (mid+1 < n-1) ? mid+1 : n-1, r2 = n-1;
        if (nums[l1] == target) return l1;
        if (nums[r1] == target) return r1;
        if (nums[l2] == target) return l2;
        if (nums[r2] == target) return r2;

        while(l1 < r1){
            int mid1 = (l1+r1)/2;
            if (nums[mid1] == target){
                return mid1;
            } else if (nums[mid1] < target){
                l1 = mid1+1;
            } else {
                r1 = mid1;
            }
        }

        while(l2 < r2){
            int mid2 = (l2+r2)/2;
            if (nums[mid2] == target){
                return mid2;
            } else if (nums[mid2] < target){
                l2 = mid2+1;
            } else {
                r2 = mid2;
            }
        }

        return -1;
    }
};
