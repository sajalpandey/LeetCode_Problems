class Solution {
public:
    void generatePermutations(int pos, vector<int>& nums,  vector<vector<int>> &ans){
        if(pos >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i = pos; i < nums.size(); i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[pos]);
            generatePermutations(pos+1, nums, ans);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermutations(0, nums, ans);
        return ans;
    }
};