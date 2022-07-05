class Solution {
public:
    string reverseWords(string s) {
        
        string result = "" ,temp = "";
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;
        for(; i<s.size();){
            
            if(isalnum(s[i])){
                temp = temp + (s[i++]);
            }
            else if(s[i]== ' '){
                reverse(temp.begin(),temp.end());
                result += temp;
                result += " ";
                temp = "";
                while(i<s.size() && s[i]==' ')
                    i++;
            }  
        }
        reverse(temp.begin(),temp.end());
        result += temp;
        reverse(result.begin(),result.end());
        i = 0;
        while(i<result.size() && result[i] == ' ')
            i++;
        result.erase(result.begin(),result.begin()+i);
        return result;
        //return "";
    }
};