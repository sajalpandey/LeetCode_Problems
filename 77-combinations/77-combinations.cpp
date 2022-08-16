class Solution {
public:
    void generateCom(int i, int n, int k, vector<vector<int>> &ans, vector<int> &temp){
        if(i > n)
            return;
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        temp.emplace_back(i+1);
        generateCom(i+1, n, k, ans, temp);
        //skip this ele
        temp.pop_back();
        generateCom(i+1, n, k, ans, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateCom(0, n, k, ans, temp);
        return ans;
    }
};