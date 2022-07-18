class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        if(k > n)
            return -1;
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0)
                count++;
            if(count == k)
                return i;
        }
        if(++count == k)
            return n;
        return -1;
    }
};