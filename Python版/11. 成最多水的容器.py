class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height)-1
        maxarea = 0
        while(r > l):
            maxarea = max(maxarea, min(height[l], height[r]) * (r-l))
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return maxarea