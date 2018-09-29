class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int len = strs.size();
        if(len <= 0) return res;
        unordered_map<string, vector<string>> anaMap;
        for(string temp : strs){
            string key = temp;
            sort(key.begin(), key.end());
            anaMap[key].push_back(temp);
        }
        for(auto it = anaMap.begin();it != anaMap.end(); it++){
            if(it->second.size() >= 1)
                res.push_back(it->second);
        }
        return res;
    }
};