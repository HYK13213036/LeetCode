class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        stringstream ss(path);
        string substr;
        while(getline(ss, substr, '/')){
            if(substr == "." or substr == "")   //string类型而不是char
                continue;
            else if(substr == ".." && res.size())
                res.pop_back();
            else if(substr != "..")
                res.push_back(substr);
        }
        string result = "";
        for(auto temp : res){
            result += '/'+temp;
        }
        return res.empty() ? "/" : result;
    }
};