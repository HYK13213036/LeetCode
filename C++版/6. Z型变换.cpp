class Solution {
public:
    string convert(string s, int nRows) {
        int step = 1, row = 0;  //1是向下，-1是向上
        vector<string> res(nRows, "");
        string result = "";
        if(nRows < 2) return s;
        for(int i = 0;i < s.length();i++){
            res[row] += s[i];    //strIng类型的优势
            if(row == nRows-1)
                step = -1;
            else if(row == 0)
                step = 1;
            row = row + step;
        }
        for(int i = 0;i < nRows;i++){
            result += res[i];
        }
        return result;
    }
};