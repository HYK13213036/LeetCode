class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> sta;
        for(int i = 0;i < n; i++){
            if(s[i] == '(')
                sta.push(')');
            else if(s[i] == '[')
                sta.push(']');
            else if(s[i] == '{')
                sta.push('}');
            else if(sta.empty())   //用来处理[']']这种情况
                return false;
            else if(sta.top() != s[i])
                return false;
            else
                sta.pop();
        }
        return sta.empty();
    }
};