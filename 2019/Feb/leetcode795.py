    def cal(A, x):
        ans = 0
        cur = 0
        for i in A:
            if i <= x:
                cur += 1
                ans += cur
            else:
                cur = 0
        return ans

class Solution:
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        return cal(A, R) - cal(A, L - 1)