class Solution {
public:
    int kthFactor(int n, int k) {
        if(k > n)
            return -1;
        int i;
        for(i = 1; i * i <= n; i++){
            if(n % i == 0)
                k--;
            if(k == 0)
                return i;
        }
        i--;
        if(i * i == n) i--;
        for(; i > 0; i--){
            if(n % i == 0)
                k--;
            if(k == 0)
                return n/i;
        }
        return -1;
    }
};