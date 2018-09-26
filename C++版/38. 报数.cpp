class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return "";
        string res = "1";
        for(int i = 1;i < n;i++){
            string t = "";
            int count = 1;
            for(int j = 1;j < res.length();j++){
                if(res[j-1] == res[j])
                    count++;
                else{
                    t.push_back('0'+count);
                    t.push_back(res[j-1]);
                    count = 1;   //恢复初值
                }
            }
            t.push_back('0'+count);
            t.push_back(res[res.length()-1]);   // 为了防止最后一个数连着，无法进入for循环中的else
            res = t;
        }
        return res;
    }
};