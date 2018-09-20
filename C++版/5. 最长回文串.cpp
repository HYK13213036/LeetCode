class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> table(s.length(), vector<bool>(s.length(), false));
        int longestbegin = 0;
        int maxlen = 1;
        
        for(int i = 0;i < n;i++){
            table[i][i] = true;
            if(i != n && s[i] == s[i+1]){
                table[i][i+1] = true;
                longestbegin = i;
                maxlen = 2;
            }
        }
        for(int len = 3;len <= n; len++){
            for(int i = 0;i < n-len+1;i++){
                int j = i + len -1;
                if(s[i] == s[j] && table[i+1][j-1]){
                    table[i][j] = true;
                    longestbegin = i;
                    maxlen = len;
                }
            }
        }
        return s.substr(longestbegin, maxlen);
    }
};

class Solution {
private:
    int left = 0, maxlen = 1;
public:
    
   void findMaxPalindrome(string s, int i, int j){
    while(i >= 0 && j < s.length() && s[i] == s[j]){
        i--; j++;
    }
    if (maxlen < j-i-1){
        left = i+1;
        maxlen = j-i-1;   //获得最大长度
    }
   }
    string longestPalindrome(string s) {
        if((s == "") || s.length() < 2)
            return s;    //极端情况
        for(int i = 0;i < s.length()-1;i++){
            // 两种情况：中间是bab，中间bb
            findMaxPalindrome(s, i, i);
            findMaxPalindrome(s, i, i+1);
        }
        return s.substr(left, maxlen);
    }
};