class Solution {
public:
    int ans = 0;
    bool checkUniqChar(string currentStr){
        unordered_set<char> s;
        for(auto c: currentStr){
            if(s.count(c))
                return false;
            s.insert(c);
        }
        return true;
    }
    void maxLenString(int index, vector<string> &arr, string currentStr){
        if(checkUniqChar(currentStr) == false) return;
        if(size(currentStr) >  ans)
            ans = size(currentStr);
        for(int i=index; i< arr.size(); i++)
            maxLenString(i+1, arr, currentStr+arr[i]);
    }
    int maxLength(vector<string>& arr) {
        string currentStr = "";
        maxLenString(0, arr, currentStr);
        return ans;
    }
};