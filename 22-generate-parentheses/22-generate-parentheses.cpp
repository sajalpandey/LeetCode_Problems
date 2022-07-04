class Solution {
public:
    void static recursiveFun(vector<string> &result, string str, int l ,int r, int length){
        if(str.size()==2*length){
            result.emplace_back(str);
            return ;
        }
        if(l<length)
            recursiveFun(result, (str+"("), l+1, r,length);
        if(r<l)
            recursiveFun(result, (str+")"), l, r+1,length);
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> result;
        
        recursiveFun(result, str , 0, 0, n);
        return result;
    }
};