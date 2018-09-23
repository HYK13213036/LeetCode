class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if(n == 0) return 0;
        if(m < n) return -1;
        int t = m-n+1;   // 只需要移动t次
        for(int i = 0;i < t; i++){
            int j = 0;
            for(;j < n; j++){
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == n){
                return i;
            }
        }
        return -1;
    }
};