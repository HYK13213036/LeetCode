class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        sort(strs.begin(), strs.end());  //排序后，只需要比较第一个和最后一个
        int n = strs.size();
        int l = min(strs[0].size(), strs[n-1].size());
        for(int i = 0;i < l; i++){
            if(strs[0][i] != strs[n-1][i])
                return strs[0].substr(0, i);
        }
        return strs[0].substr(0, l);  //全都符合的话，最大前缀就是本身了
    }
};