class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+size(nums)/2, nums.end());
        int med = nums[size(nums)/2];
        int res = 0;
        for(int i=0; i < size(nums); i++)
        {
            res += abs(med - nums[i]);
        }
        return res;
    }
};