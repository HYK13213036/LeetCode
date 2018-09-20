class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        book = {'I': 1, 'V': 5, 'X': 10, 'L' :50, 
                'C' : 100, 'D': 500, 'M': 1000}
        res = 0
        for i in range(len(s)):
            if i > 0 and book[s[i]] > book[s[i-1]]:
                res += book[s[i]] - 2*book[s[i-1]]
            else:
                res += book[s[i]]
        return res;