class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int num = 1;
        int carry = num;
        for(int i = digits.size()-1; i >= 0; i--){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};