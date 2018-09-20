class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s), plen = strlen(p);
        vector< vector<bool> > dp( slen+1, vector<bool>(plen+1, false) ); //增加一行用于特例
        dp[0][0] = true;
        for(int i = 1;i < plen + 1; i++){  //s为空的情况
            if(p[i -1] == '*')
                dp[0][i] = dp[0][i-2];
        }
        for(int i = 1;i < slen + 1; i++){
            for(int j = 1;j < plen + 1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    if(p[j-2] != s[i-1] && p[j-2] != '.'){  // *前字符匹配到0次
                        dp[i][j] = dp[i][j-2];
                    }else{
                        if(p[j-2] == s[i-1] || p[j-2] == '.'){
                            dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                            // *前匹配到0次、1次、多次
                        }
                    }
                }
            }
        }
        return dp[slen][plen];
    }
};