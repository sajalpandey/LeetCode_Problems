class Solution {
public:
    void generateComb(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &cmb, int i)
    {
        if(target == 0){
            ans.push_back(cmb);
            return;
        }
        if(i >= size(candidates))
            return;
        if(candidates[i] <= target){
            cmb.emplace_back(candidates[i]);
            generateComb(candidates, target-candidates[i], ans, cmb, i);
            cmb.pop_back();
            generateComb(candidates, target, ans, cmb, i+1);
        }
        else 
            return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cmb;
        generateComb(candidates, target, ans, cmb, 0);
        return ans;
    }
};