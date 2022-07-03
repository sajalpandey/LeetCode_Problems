class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> temp;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                temp.push_back(i);
            else if(s[i]==')'){
                if(temp.size()==0)
                    s.erase(s.begin()+i),i--;
                else
                    temp.pop_back();
            }
        }
        while(temp.size()>0){
            s.erase(s.begin()+temp.back());
            temp.pop_back();
        }
        return s;
    }
};