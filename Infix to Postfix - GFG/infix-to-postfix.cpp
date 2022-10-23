//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch)
    {
        if(ch == '^')
            return 3;
        else if(ch == '*' || ch == '/')
            return 2;
        else
            return 1;
    }
    string infixToPostfix(string s) {
        string result = "";
        stack<char> opr;
        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                result += s[i];
            }
            else if(s[i] == '^' || s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-')
            {
                while(!opr.empty() && priority(s[i]) <= priority(opr.top()) && opr.top()!='(')
                {
                    result += opr.top();
                    opr.pop();
                }
                opr.push(s[i]);
            }
            else if(s[i] =='(')
                opr.push(s[i]);
            else if(s[i] == ')')
            {
                while(!opr.empty() && opr.top()!='(')
                {
                    result += opr.top();
                    opr.pop();
                }
                opr.pop();
            }
        }
        while(!opr.empty())
        {
            result += opr.top();
            opr.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends