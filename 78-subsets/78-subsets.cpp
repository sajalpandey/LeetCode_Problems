class Solution {
public:
    vector<vector<int>> generateSubsets(int i, vector<int>& nums){
        if(i >= nums.size())
            return {{}};
        vector<vector<int>> partial = generateSubsets(i+1, nums);
        vector<vector<int>> ans;
        for(auto &v: partial)
            ans.push_back(v);
        for(auto &v: partial){
            v.insert(v.begin(),nums[i]);
            ans.push_back(v);
        }
        
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return generateSubsets(0, nums);
    }
};