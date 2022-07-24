class Solution {
public:
    int rightSearch(vector<int> nums, int low, int high, int target){
        int ans = -1;
        while(low <= high){
            int middle = low + (high - low)/2;
            if(nums[middle] == target){
                ans = middle;
                low = middle + 1;
            }
            else if(nums[middle] < target)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return ans;
    }
    int leftSearch(vector<int> nums, int low, int high, int target){
        int ans = -1;
        while(low <= high){
            int middle = low + (high - low)/2;
            if(nums[middle] == target){
                ans = middle;
                high = middle -1;
            }
            else if(nums[middle] < target)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.emplace_back(leftSearch(nums, 0, nums.size()-1, target));
        res.emplace_back(rightSearch(nums, 0, nums.size()-1, target));
        return res;
    }
};