//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
void reverse(queue<int> &q){
    if(q.empty())
        return;
    int ele = q.front();
    q.pop();
    reverse(q);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k) {
    queue<int> res;
    while(!q.empty())
    {
        res.push(q.front());
        k--;
        q.pop();
        if(k==0){
            reverse(res);
            while(!q.empty()){
                res.push(q.front());
                q.pop();
            }
            break;
        }
    }
    return res;
}