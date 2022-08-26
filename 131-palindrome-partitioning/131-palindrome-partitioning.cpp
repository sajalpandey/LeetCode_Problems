class Solution {
public:
    bool isPalindrome(string t, int i, int j){
        if(size(t) == 0)
            return false;
        while(i<j){
            if(t[i]!=t[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void partitionString(int index, string s, vector<vector<string>> &ans, vector<string> &tempAns)
    {
        if(index >= size(s)){
            ans.push_back(tempAns);
            return;
        }
        for(int i = index; i<size(s); i++){
            if(isPalindrome(s, index, i)){
                string sstr = s.substr(index, i-index+1);
                tempAns.emplace_back(sstr);
                partitionString(i+1, s, ans, tempAns);
                //Backtracking
                tempAns.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tempAns;
        partitionString(0, s, ans, tempAns);
        return ans;
    }
};