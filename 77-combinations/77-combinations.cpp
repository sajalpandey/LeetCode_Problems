class Solution {
public:
    void generateCom(int start, int n, int k, vector<vector<int>> &ans, vector<int> &temp){  
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(start >= n)
            return;
        for(int i = start; i < n; i++){
            temp.emplace_back(i+1);
            generateCom(i+1, n, k, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateCom(0, n, k, ans, temp);
        return ans;
    }
};