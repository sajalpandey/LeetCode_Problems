class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int med = nums[size(nums)/2];
        int res = 0;
        for(int i=0; i < size(nums); i++)
        {
            res += abs(med - nums[i]);
        }
        return res;
    }
};