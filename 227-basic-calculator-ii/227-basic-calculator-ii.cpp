class Solution {
public:
    int calculate(string s) {
        
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        if(size(s)==1)
            return stoi(s);
        stack<int> num;
        char prevOp = '+';
        int temp = 0,res=0;
        for(int i=0; i<s.size();++i){
            if(isdigit(s[i]))
                temp = temp * 10 +(s[i] -'0');
            if(!isdigit(s[i]) || i == s.size()-1){
                if(prevOp == '+')
                    num.push(temp);
                else if(prevOp == '-')
                    num.push(-temp);
                else if(prevOp == '/'){
                    int ele = num.top() ;num.pop();
                    num.push(ele/temp);
                } else if(prevOp == '*'){
                    int ele = num.top(); num.pop();
                    num.push(ele*temp);
                }
                
                temp = 0;
                prevOp = s[i];
            }
        }
        
        while(!num.empty()){
            res += num.top() ;num.pop();
        }
        return res;
    }
};