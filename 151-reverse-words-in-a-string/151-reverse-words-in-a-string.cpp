class Solution {
public:
    string reverseWords(string s) {
        /*
        1. Remove the leading spaces
        2. Copy the word at the positions of spaces
        3. Now reverse the word
        4. resize the array
        5. reverse the whole string and return the result
        */
        int i = 0, j = 0, noOfWords = 0, left = 0;
        
        while(i<s.size()){
            
            while(i<size(s) && s[i] == ' ')
                i++;
            if(i<size(s) && noOfWords)
                s[j++] = ' ';
            left = j;
            while(i<size(s) && s[i]!=' ')
                s[j++] = s[i++];
            reverse(s.begin()+left, s.begin()+j);
            
            noOfWords++;
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        return s;
    }
};