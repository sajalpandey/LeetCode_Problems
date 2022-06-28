class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxSoFar = nums[0], minSoFar=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int val = max({nums[i]*maxSoFar, nums[i]*minSoFar,nums[i]});
            minSoFar = min({nums[i]*minSoFar,nums[i]*maxSoFar,nums[i]});
            maxSoFar = val;
            
            res = max(res,maxSoFar);
        }
    
        return res;
    }
};