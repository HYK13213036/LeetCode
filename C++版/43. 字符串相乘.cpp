class Solution {
public:
    string multiply(string num1, string num2) {
	    string res(num1.size() + num2.size(), '0');
	    for (int i = num1.size() - 1, d = res.size()-1; i >= 0; i--, d--){
		    int carry = 0, k = d;
		    for (int j = num2.size()-1; j >= 0; j--, k--){
			    int a = num1[i] - '0';
			    int b = num2[j] - '0';
			    a = a * b + carry + (res[k] - '0');
			    carry = a/10;
			    res[k] = a%10 + '0';  //模拟手写进位
		    }
		    while (carry){
			    int sum = carry + (res[k] - '0');
			    carry = sum / 10;
			    res[k--] = sum % 10 + '0';   //最高位有进位的情况
		    }
	    }
	    string::iterator ite = res.begin();
	    while(*ite == '0' && ite != --res.end())    ite++;
	    res.erase(res.begin(),ite);    //消除前面没有使用到的零
	    return res;
    }

};