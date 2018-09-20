class Solution {
public:
    bool isPalindrome(int x) {
        int reverse = 0;
        if ((x < 0 || x%10 == 0) && (x != 0)) return false;  //去除特例
        while(x > reverse){     //当商小于reverse时候，说明到一半了
            reverse = reverse*10 + x % 10;
            x = x / 10;
        }
        return (reverse/10 == x || reverse == x);   //当奇个数时，reverse的最后一位为中间数
    }
};