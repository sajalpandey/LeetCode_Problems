class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        if(num1 == "0" || num2 == "0")
            return "0";
        
        vector<int> temp(size(num1) + size(num2), 0);
        
        for(int i=num1.size()-1; i >= 0 ;--i){
            for(int j = num2.size()-1; j >= 0; --j){
                temp[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                temp[i+j] += temp[i+j+1]/10;
                temp[i+j+1] %= 10; 
            }
        }
        int i = 0;
        while(i<size(temp) && temp[i] == 0)
            i++;
        while(i < size(temp))
            res = res + to_string(temp[i++]) ;
        return res;
    }
};