class Solution {
public:
    int romanToInt(string s) {
        map<char,int> book = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                              {'C', 100}, {'D', 500}, {'M', 1000}};
        int res=0;
        for(int i=0;i<s.length();i++)
            if(i > 0 && book[s[i]] > book[s[i-1]]) res+= book[s[i]] - 2 * book[s[i-1]];
            else res+= book[s[i]];
        return res;
    }
};