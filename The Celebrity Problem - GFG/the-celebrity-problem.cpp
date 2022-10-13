//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i = 0; i < M.size(); i++)
        {
            bool rowFlag = 1, colFlag = 1;
            for(int k = 0; k < M.size(); k++)
            {
                if(M[i][k] == 1)
                    rowFlag = 0;
            }
            for(int k = 0; k < M.size(); k++)
            {
                if(i!=k && M[k][i] == 0)
                    colFlag = 0;
            }
            if(rowFlag && colFlag)
                return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends