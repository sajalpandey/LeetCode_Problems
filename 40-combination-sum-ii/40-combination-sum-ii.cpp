class Solution {
public:
    void generateCom(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &cmb, int i)
    {
        if(target == 0){
            ans.push_back(cmb);
            return;
        }
        if(i >= size(candidates))
            return;
        if(candidates[i] <= target){
            cmb.emplace_back(candidates[i]);
            generateCom(candidates, target-candidates[i], ans, cmb, i+1);
            cmb.pop_back();
            while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
                i++;
            generateCom(candidates, target, ans, cmb, i+1);
        }
        else
            return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cmb;
        generateCom(candidates, target, ans, cmb, 0);
        return ans;
    }
};