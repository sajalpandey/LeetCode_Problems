class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=size(s))
            return s;
        vector<pair<int ,int>> vp;
        string result = "";
        int n = 1, flag=0;
        for(int i=0; i<size(s); ++i){
            vp.emplace_back(n,i);
            if(flag == 0)
                n++;
            else
                n--;
            if(n>=numRows){
                flag = 1;
            } else if(n<=1)
                flag =0;
        }
        sort(vp.begin(),vp.end());
        for(auto & ele :vp)
            result += s[ele.second];
        return result;
    }
};