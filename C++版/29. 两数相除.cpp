class Solution {
public:
    int divide(int dividend, int divisor) {
       if(divisor == 0)
            return INT_MAX;
        int flag = (dividend ^ divisor) >> 31 ? -1 : 1;
        long long diviD = labs(dividend),diviS = labs(divisor);
        int res = 0;
        while(diviD >= diviS)
        {
            long long sub = diviS,k=1;
            while((sub<<1) <= diviD)
            {
                sub <<= 1;
                k <<= 1;
            }
            diviD -= sub;
            res += k;
        }
        return res*flag;
    }
};