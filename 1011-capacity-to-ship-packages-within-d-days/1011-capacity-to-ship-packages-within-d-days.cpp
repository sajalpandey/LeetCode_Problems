class Solution {
public:
    bool shippingPossible(vector<int>& weights, int mid, int days){
        
        int capacity = 0;
        for(int i = 0; i < size(weights); i++){
            if(capacity + weights[i] <= mid)
                capacity += weights[i];
            else{
                days--;
                if(days == 0 || weights[i] > mid)
                    return false;
                
                capacity = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0, end = 0, mid, ans = -1;
        for(auto &ele : weights)
            end += ele;
        
        while(start <= end){
            mid = start + (end - start)/2;
            if(shippingPossible(weights, mid, days)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};