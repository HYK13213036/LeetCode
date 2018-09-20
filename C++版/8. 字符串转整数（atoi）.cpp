class Solution {
public:
    int atoi(const char *str) {
        int k = 0;
		long ans = 0L;   //建议设为long型，为了判断溢出
		bool sig = false;   //默认正数
        string s(str);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				k = i;
				break;
			}
		}
		if (s[k] == '-' || s[k] == '+') {
			sig = s[k] == '-' ? true : false; 
            k++;
		}
		while (s[k] >= '0' && s[k] <= '9') {
			ans = ans * 10 + (s[k] - '0');
			k++;
            if ( (sig ? -1 : 1) * ans >= INT_MAX)  return INT_MAX;  //在这里进行溢出判断
		    if ( (sig ? -1 : 1) * ans <= INT_MIN)  return INT_MIN;
		}
		ans =  (sig ? -1 : 1) * ans;
		return ans;
    }
};