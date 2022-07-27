class Solution {
public:
    double myPow(double x, int n) {
        int sign = n;
        long num = abs(n);
        double ans = 1;
        while(num){
            if(num&1)
                ans = ans * x;
            x = x * x;
            num = num>>1;
        }
        if(sign < 0)
            return 1/ans;
        return ans;
    }
};