class Solution {
public:
    void generatePermutations(int pos, vector<int>& nums, set<vector<int>> &s){
        
        if(pos >= nums.size()){
            s.insert(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            swap(nums[i], nums[pos]);
            generatePermutations(pos+1, nums, s);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        generatePermutations(0, nums, s);
        for(auto &vec: s)
            ans.emplace_back(vec);
        return ans;
    }
};