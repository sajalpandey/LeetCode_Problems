class Solution {
public:
    void generateSubset(vector<int>& nums, int i, set<vector<int>> &s, vector<int> subset){
        if(i >= nums.size()){
            //sort(subset.begin(),subset.end());
            s.insert(subset);
            return;
        }
        subset.emplace_back(nums[i]);
        generateSubset(nums, i+1, s, subset);
        subset.pop_back();
        generateSubset(nums, i+1, s, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        generateSubset(nums, 0, s, subset);
        for(auto &ele: s)
            ans.push_back(ele);
        return ans;
    }
};