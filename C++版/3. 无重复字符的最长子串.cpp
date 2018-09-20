class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxlen = 0;
        unordered_map<char, int> charmap;
        if(s.length() == 0) return 0;
        for(int i=0; i < s.length();i++){
            if(charmap.find(s[i]) != charmap.end()){
                left = max(left, charmap[s[i]] + 1);
            }
            maxlen = max(maxlen, i-left+1);
            charmap[s[i]] = i;
        }
        return maxlen;
    }
};