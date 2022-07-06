class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=size(s))
            return s;
        vector<string> vp(numRows+1,"");
        string result = "";
        int n = 1, flag=0;
        for(int i=0; i<size(s); ++i){
            vp[n] += s[i];
            if(flag == 0)
                n++;
            else
                n--;
            if(n>=numRows){
                flag = 1;
            } else if(n<=1)
                flag =0;
        }
       
        for(int i=1 ;i<=numRows; i++)
            result += vp[i];
        return result;
    }
};