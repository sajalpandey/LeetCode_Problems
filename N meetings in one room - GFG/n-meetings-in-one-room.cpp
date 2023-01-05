//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second< b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> interval;
        for(int i = 0; i < n; i++){
            interval.push_back(make_pair(start[i],end[i]));
        }
        sort(interval.begin(),interval.end(),cmp);
        int meetings = 1;
        int endd = interval[0].second;
        for(int i = 1; i < interval.size(); i++){
            if(endd < interval[i].first){
                meetings++;
                endd = interval[i].second;
            }
        }
        return meetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends