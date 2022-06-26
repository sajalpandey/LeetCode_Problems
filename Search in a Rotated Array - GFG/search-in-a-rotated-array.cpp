// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
    //complete the function here
        if(l>h)
            return -1;
        int mid = (l+h)/2;
        // cout<<"l: "<<l<<" h: "<<h<<endl;
        // cout<<"mid: "<<mid<<"midEle: "<<arr[mid]<<endl;
        if(arr[mid]==key)
            return mid;
        else if(arr[l]<=arr[mid]){
            //cout<<"left"<<endl;
        if(key<arr[mid] && key>=arr[l])
            return search(arr,l,mid-1,key);
        else 
            return search(arr,mid+1,h,key);
        }
        else if(arr[mid]<=arr[h]){
            //cout<<"right"<<endl;
            if(key>arr[mid] && key<=arr[h])
                return search(arr,mid+1,h,key);
            else
                return search(arr,l,mid-1,key);
        }
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends