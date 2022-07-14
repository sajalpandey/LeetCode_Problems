class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minN = INT_MAX, res = 0;
        for(int i=0; i < size(nums); i++)
            if(minN > nums[i])
                minN = nums[i];
        for(int i=0; i < size(nums); i++)
            res += nums[i] - minN;
        
        return res;
    }
};