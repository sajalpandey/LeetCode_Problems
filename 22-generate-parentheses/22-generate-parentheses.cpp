class Solution {
public:
    void static recursiveFun(vector<string> &result, string str, int l ,int r){
        if(l==0 && r==0){
            result.emplace_back(str);
            return ;
        }
        if(r<l || l < 0)
            return;
        recursiveFun(result, (str+"("), l-1, r);
        recursiveFun(result, (str+")"), l, r-1);
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> result;
        
        recursiveFun(result, str , n, n);
        return result;
    }
};