class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = size(nums);
        int maxP = max(nums[0] * nums[1] * nums[n-1] , nums[n-1] * nums[n-2] * nums[n-3]);
        return maxP;
    }
};