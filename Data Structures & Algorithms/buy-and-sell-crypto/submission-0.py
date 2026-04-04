class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        mn = prices[0]
        for i in prices:
            profit = max(profit,i-mn)
            if i<mn:
                mn=i
        return profit