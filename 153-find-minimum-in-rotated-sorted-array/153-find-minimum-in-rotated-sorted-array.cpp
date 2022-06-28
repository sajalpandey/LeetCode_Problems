class Solution {
public:   
    int findMin(vector<int>& arr) {
        if(arr.size()<2)
             return arr[0];
        int l=0,h=arr.size()-1,mid;
        if(arr[l]<arr[h])
            return arr[l];
        while(l<=h){
            
            mid = l + (h-l)/2;
            if(mid>l && arr[mid]<arr[mid-1])
                return arr[mid];
            if(mid<h && arr[mid]>arr[mid+1])
                return arr[mid+1];
            if(arr[l]<arr[mid])
                l = mid+1;
            else
                h = mid -1;
        }
        return -1;
    }
};