class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = {}
        for i in range(len(nums)-2):
            l = i+1
            r = len(nums)-1
            while l<r:
                if nums[i]+nums[l]+nums[r]>0:
                    r-=1
                    while r>=0 and nums[r]==nums[r+1]:
                        r-=1
                elif nums[i]+nums[l]+nums[r]<0:
                    l+=1
                    while l<=len(nums)-1 and nums[l]==nums[l-1]:
                        l+=1
                else:
                    ans[(nums[i],nums[l],nums[r])]=1
                    l+=1
                    r-=1
                    while r>0 and nums[r]==nums[r+1]:
                        r-=1
                    while l<len(nums)-1 and nums[l]==nums[l-1]:
                        l+=1
        return [i for i in ans]