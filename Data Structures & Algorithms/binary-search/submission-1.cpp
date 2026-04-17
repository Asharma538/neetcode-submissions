class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_pointer = 0, right_pointer = nums.size()-1;

        while ( left_pointer < right_pointer ){
            int mid_pointer = (left_pointer+right_pointer)/2;

            if (nums[mid_pointer] == target) return mid_pointer;
            else if (nums[mid_pointer] < target) left_pointer = mid_pointer+1;
            else right_pointer = mid_pointer;
        }
        return nums[left_pointer] == target ? left_pointer : -1;
    }
};
