// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void static recursiveFun(vector<string> &result, string str, int l ,int r){
        if(l==0 && r==0){
            result.emplace_back(str);
            return ;
        }
        if(r<l || l < 0)
            return;
        recursiveFun(result, (str+"("), l-1, r);
        recursiveFun(result, (str+")"), l, r-1);
    }
    vector<string> AllParenthesis(int n) 
    {
        string str = "";
        vector<string> result;
        
        recursiveFun(result, str , n, n);
        return result;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends