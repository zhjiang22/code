class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        ans = 0
        minfix = 999999
        for i in range(n):
            ans = max(ans, prices[i] - minfix)
            minfix = min(minfix, prices[i])
        return ans

