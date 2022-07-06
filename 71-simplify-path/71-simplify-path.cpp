class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string result = "",temp ="";
        for(int i=0; i<size(path); ++i){
            temp= "";
            while(i<size(path) && path[i]!= '/')
                temp += path[i++];
            if(temp == ".")
                continue;
            if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            if(temp!=".." && temp!="." && temp!="")
                st.push(temp);
        }
        
        if(st.empty())
            return "/";
        while(!st.empty()){
            result =  "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};