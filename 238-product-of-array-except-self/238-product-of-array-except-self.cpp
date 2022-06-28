class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size() , prod=1;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;--i){
            res[i] = prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=0;i<nums.size();i++){
            res[i] = res[i] * prod;
            prod *= nums[i];
        }
        return res;
    }
};