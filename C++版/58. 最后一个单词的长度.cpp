class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int count = 0;
        if(len == 0)
            return 0;
        for(int i = len - 1; i >= 0;i--){
            if(s[i] == ' ' && count)    // 出现空格，而且count不为零
                break;
            if(s[i] == ' ')
                continue;
            count += 1;
        }
        return count;
    }
};




class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string str;
        while(ss >> str);
        return str.length();
    }
};