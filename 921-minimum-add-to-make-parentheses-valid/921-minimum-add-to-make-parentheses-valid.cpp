class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto &e: s){
            if(e == '(')
                st.push(e);
            else{
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(e);
            }
        }
        
        return st.size();
    }
};