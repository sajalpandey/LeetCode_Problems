class Solution {
public:
    void makePrefixTable(vector<int> & prefix,int n,string needle){
        if(n<2)
            return;
        int i=1,j=0;
        while(i<n){
            if(needle[i]==needle[j]){
                prefix[i]=j+1;
                ++i,++j;
            } else {
                if(j>0)
                    j=prefix[j-1];
                else
                    prefix[i++]=0;
            }
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
            return -1;
        if(needle.size()==0)
            return 0;
        vector<int> prefix (needle.size(),0);
        makePrefixTable(prefix,needle.size(),needle);
        /*searching the pattern*/
        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                ++i,++j;
                if(j==needle.size())
                    return (i-j);
            }
            else{
                if(j>0)
                    j=prefix[j-1];
                else
                    j=0,++i;
            }
        }
        return -1;
    }
};