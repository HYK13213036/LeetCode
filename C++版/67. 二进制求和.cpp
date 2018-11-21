class Solution {
public:
    string addBinary(string a, string b) {
        int length = max(a.size(), b.size());
        string res(length+1, ' ');  //res比max多一位
        char carry = '0';
        while(length > a.size())
            a = "0" + a;
        while(length > b.size())
            b = "0" + b;
        for(int i = length-1; i >= 0; --i){
            int ch = a[i] + b[i] + carry - 3 * '0';
            switch(ch){
                case 3: {
                    res[i+1] = '1'; carry = '1'; break;
                }
                case 2: {
                    res[i+1] = '0'; carry = '1'; break;
                }
                default:{
                    res[i+1] = ch + '0'; carry = '0'; break;
                }
            }
        }
        if(carry == '1') res[0] = '1';
        else res = res.substr(1);
        return res;
    }
};