class Solution {
public:
    int mySqrt(int x) {
       if(x < 0)
                return -1;
            long res = x;
            while(res * res > x)
                res = ((res + x / res) >> 1); //牛顿法
            return res;
        }
};