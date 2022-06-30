// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> ump;
	    int res = 0, curr_sum = 0;
	    for(int i=0; i<n; ++i){
	        
	        curr_sum+= arr[i];
	        int module = ((curr_sum % k)+ k) % k;
	        if(module == 0)
	            res = i + 1;
	        else if(ump.find(module)==ump.end())
	            ump[module] = i;
	        else
	            if(res < (i - ump[module]))
	                res = i - ump[module];
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends