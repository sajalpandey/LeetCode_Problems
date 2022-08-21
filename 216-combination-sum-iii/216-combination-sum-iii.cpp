class Solution {
public:
    void generateCmb3(int k, int n, int num, vector<vector<int>> &ans, vector<int> &cmb)
    {
        if(cmb.size() == k && n==0){
            ans.push_back(cmb);
            return;
        }
        if(num > 9 || size(cmb) > k)
            return;
        if(num <= n){
            cmb.emplace_back(num);
            generateCmb3(k, n-num, num+1, ans, cmb);
            cmb.pop_back();
            generateCmb3(k, n, num+1, ans, cmb);
        }
        else 
            return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cmb;
        generateCmb3(k, n, 1, ans, cmb);
        return ans;
    }
};