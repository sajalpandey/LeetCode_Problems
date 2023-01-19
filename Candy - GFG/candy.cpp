//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        int sum=0;
        vector<int> candy(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1])
                candy[i]=candy[i-1] + 1;
        }
        sum = candy[ratings.size()-1];
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1])
                candy[i] = max(candy[i] ,candy[i+1] + 1);
            sum+=candy[i];
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends