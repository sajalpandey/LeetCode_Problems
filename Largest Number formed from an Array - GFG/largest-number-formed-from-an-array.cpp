// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static int myCompare(string num1, string num2){
	    string temp1 = num1+num2;
	    string temp2 = num2+num1;
	    
	    return temp1.compare(temp2)>0 ? 1: 0;
	}
	string printLargest(vector<string> &arr) {
	    // code here
	    
	    string ans = "";
	    sort(arr.begin(), arr.end(), myCompare);
	    for(auto str : arr)
	        ans += str;
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends