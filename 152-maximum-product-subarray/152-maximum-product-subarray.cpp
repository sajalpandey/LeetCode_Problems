class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxSoFar = nums[0], minSoFar=nums[0];
        
        /*At every step calculate the max product either by maxvalue or min value*/
        for(int i=1;i<nums.size();i++){
            int val = max(max(nums[i]*maxSoFar, nums[i]*minSoFar),nums[i]);
            minSoFar = min(min(nums[i]*minSoFar,nums[i]*maxSoFar),nums[i]);
            maxSoFar = val;
            
            res = max(res,maxSoFar);
        }
    
        return res;
    }
};