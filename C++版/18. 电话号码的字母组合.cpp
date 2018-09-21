class Solution {
private:
    map<char, string> charmap= {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    string temp;
public:
    void combine(string &digits, int start){
        if(start == digits.length()){    // 回溯法也就是递归的方法
            res.push_back(temp); return;
        }
        for(int i = 0; i < charmap[digits[start]].length();i++){
            temp += charmap[digits[start]][i];
            combine(digits, start+1);
            temp.pop_back();   
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            res.push_back(digits);
            return res;
        }
        combine(digits, 0);
        return res;
    }
};