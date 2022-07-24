class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, middle;
        while(low < high){
            middle = low + (high - low)/2;
            if(arr[middle] < arr[middle+1])
                low = middle + 1;
            else
                high = middle;
        }
        return low;
    }
};