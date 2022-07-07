class Solution {
public:
    void justify(string &text, int n)
    {
        int spaces = n - size(text);
        int r = spaces;
        //cout<<spaces<<endl;
        while(1){
            for(int i=0; i<size(text); ++i){
                if(text[i] == ' '){
                    while(i<size(text) && text[i]==' ')
                        i++;
                    text.insert(i-1," ");
                    spaces --;
                    
                }
                if(spaces == 0)
                    return;
            }
            //cout<<"spaces: "<<spaces<<endl;
            if(spaces == r){
                while(spaces){
                    text.insert(size(text)," ");
                    spaces--;
                }
                if(spaces == 0)
                    return;
            }
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string temp = "";
        for(auto & word : words){
            if(temp == "")
                temp += word;
            else{
                if((size(temp)+size(word)+1)<=maxWidth){
                    temp += " ";
                    temp += word;
                }else{
                    
                    justify(temp,maxWidth);
                   
                    result.emplace_back(temp);
                    temp = "";
                    temp += word;
                }
            }
        }
        if(size(temp)+1<=maxWidth){
            int spaces = maxWidth - size(temp);
            while(spaces){
                temp.insert(size(temp)," ");
                spaces--;
            }
        }
        result.emplace_back(temp);
        return result;
    }
};