class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact {1,1,2,6,24,120,720,5040,40320,362880};
        string ans = "";
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.emplace_back(i);
        int N = n;
        k--;
        while(1){
            if(size(ans) == N)
                return ans;
            int bracket = k/fact[n-1];
            ans += to_string(nums[bracket]);
            nums.erase(nums.begin()+bracket);
            k = k%fact[n-1];
            n--;
        }
        return ans;
    }
};