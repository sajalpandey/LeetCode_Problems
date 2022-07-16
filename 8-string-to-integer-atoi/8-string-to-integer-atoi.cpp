class Solution {
public:
    int myAtoi(string s) {
        int res  = 0, i = 0, sign = 1;
        //Ignore leading spaces
        while(i<size(s) && s[i] == ' ')
            i++;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }else if(s[i] == '+')
            i++;
        while(i < size(s))
        {
            if(isdigit(s[i])){
                if(res > INT_MAX/10 || (res == INT_MAX/10 && (s[i] - '0') > 7)){
                    if(sign < 0)
                        return INT_MIN;
                    return INT_MAX;
                }
                
                res = res * 10 + (s[i] - '0');
                //cout<<res<<endl;
                i++;
            }
            else 
                break;
        }
        
        return sign*res;
    }
};