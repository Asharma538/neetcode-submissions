class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hsh = [0]*len(nums)
        for i in nums:
            if hsh[i-1]==1:
                return i
            else:
                hsh[i-1] = 1
        return -1