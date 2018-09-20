class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # 动态规划的思想dp[i][j]的匹配项不包含i,j
        slen, plen = len(s), len(p)
        dp = [[False for i in range(plen+1)] for i in range(slen+1)]  # 注意创建的行和列
        dp[0][0] = True
        for i in range(1, plen+1):
            if p[i-1] == '*':
                dp[0][i] = dp[0][i-2]
        for i in range(1, slen+1):
            for j in range(1, plen+1):
                if s[i-1] == p[j-1] or p[j-1] == '.':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    if s[i-1] != p[j-2] and p[j-2] != '.':
                        dp[i][j] = dp[i][j-2]  #匹配零项
                    else:
                        dp[i][j] = dp[i][j-1] or dp[i][j-2] or dp[i-1][j]
        return dp[slen][plen]