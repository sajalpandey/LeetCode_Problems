class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int numbers = pow(2, size(nums));
        for(int i = 0; i < numbers; i++){
            subset.clear();
            
            for(int j = 0; j < nums.size(); j++){
                if(i & 1<<j){
                    subset.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(subset);
        }
        return ans;
    }
};