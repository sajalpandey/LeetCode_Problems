class Solution {
public:
    string static makeJustifyLine(vector<string>& words, int start, int end, int len, int maxLen)
    {
        string ans = "";
        int spacesToAppend = 1;
        int extraSpaces = 0;
        if(start!=end)
        {
            spacesToAppend = (maxLen - len) /(end - start);
            extraSpaces = (maxLen - len)% (end - start);
        }
        
        for (int i = start; i<=end; i++)
        {
            ans += words[i];
            if(i!=end)
            {
                if(end == size(words) -1)
                    ans += " ";
                else
                {
                    for(int j=1; j<=spacesToAppend; j++)
                        ans += " ";
                    if(extraSpaces)
                    {
                        ans += " ";
                        extraSpaces--;
                    }
                }
            }
            
        }
        
        while(size(ans)<maxLen)
            ans += " ";
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int word = 0, j, charSoFar;
        while(word<size(words))
        {
            j = word -1;
            charSoFar = 0;
            while(j+1<size(words) && charSoFar + size(words[j+1]) + (j-word+1) <= maxWidth)
            {
                charSoFar += size(words[j+1]);
                j++;
            }
            result.emplace_back(makeJustifyLine(words, word, j, charSoFar, maxWidth));
            
            word = j+1;
            
        }
        return result;
    }
};