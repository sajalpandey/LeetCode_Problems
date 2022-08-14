class Solution {
public:
    void generateSubsets(int i, vector<int>& nums, vector<int> &subset, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.emplace_back(nums[i]);
        generateSubsets(i+1, nums, subset, ans);
        
        subset.pop_back();
        generateSubsets(i+1, nums, subset, ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        generateSubsets(0, nums, subset, ans);
        return ans;
    }
};