class Solution {
public:
    int reverse(int x) {
        int res = 0, sign = 1, last_digit;
        if( x < 0)
            sign = -1;
        x = abs(x);
        while( x > 0 )
        {
            last_digit = x % 10;
            if( res  > INT_MAX / 10)
                return 0;
            res = res * 10 + last_digit;
            x /= 10;
        }
        
        if(sign < 0 && sign * res < INT_MIN)
            return 0;
        return (sign * res);
    }
};