class Solution {
public:
    void generateCom(int i, int n, int k, vector<vector<int>> &ans, vector<int> &temp){
        
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i > n)
            return;
        temp.emplace_back(i);
        generateCom(i+1, n, k, ans, temp);
        //skip this ele
        temp.pop_back();
        generateCom(i+1, n, k, ans, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateCom(1, n, k, ans, temp);
        return ans;
    }
};