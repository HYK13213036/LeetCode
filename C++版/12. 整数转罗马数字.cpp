class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> key = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> value={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0;i < key.size(); i++){
            int count = num / key[i];
            for(int j = 0;j < count; j++){
                res += value[i];
            }
            num %= key[i];
        }
        return res;
    }
};