class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i<j){
            if(isalnum(s[i])){
                if(isalnum(s[j])){
                    if(s[i]!=s[j])
                        return false;
                    i++,j--;
                }
                else
                    --j;
            }
            else
                i++;
        }
        return true;
    }
};