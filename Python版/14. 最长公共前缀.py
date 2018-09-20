class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        strs = sorted(strs)
        l = min(len(strs[0]), len(strs[len(strs)-1]))
        for i in range(l):
            if(strs[0][i] != strs[len(strs)-1][i]):
                return strs[0][0:i]
        return strs[0][0:l]