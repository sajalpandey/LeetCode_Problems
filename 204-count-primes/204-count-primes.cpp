class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> prime(n+1 , 1);
        
        for(int i = 2; i < n; i++){
            
            if(prime[i]){
                count++;
                
                for(int j = 2 * i; j < n; j = j + i)
                    prime[j] = 0;
            }
        }
        return count;
    }
};