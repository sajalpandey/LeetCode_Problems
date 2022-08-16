class Solution {
public:
    void generateSubset(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> subset){
        if(i >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        generateSubset(nums, i+1, ans, subset);
        subset.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        generateSubset(nums, i+1, ans, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        generateSubset(nums, 0, ans, subset);
        return ans;
    }
};