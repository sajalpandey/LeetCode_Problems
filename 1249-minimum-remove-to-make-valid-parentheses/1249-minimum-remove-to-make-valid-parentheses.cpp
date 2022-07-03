class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
        1. if open paranethesis then will insert index in set or map
        2. if close ) encountered
            a) if opening is encountered before then will simply remove the index of openinng paraenthesis from set or map
            b) if open not entcounteres then will delete this charater
        */
        
        vector<int> temp;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                temp.push_back(i);
            else if(s[i]==')'){
                if(temp.size()==0)
                    s.erase(s.begin()+i--);
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