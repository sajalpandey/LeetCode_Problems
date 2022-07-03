class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char,int> mp;
        if(!str.size())
            return 0;
        int res=0,j=0;
        for(int i=0;i<str.size();++i){
            if(mp.find(str[i])!=mp.end() && j<=mp[str[i]])
                    j=mp[str[i]]+1;
            
            mp[str[i]]=i;
            int length=i-j;
            if(res<length)
                res=length;
            
        }
        return (++res);
    }
};