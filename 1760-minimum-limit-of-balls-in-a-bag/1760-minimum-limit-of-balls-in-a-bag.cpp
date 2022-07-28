class Solution {
public:
    bool possiblePenalty(vector<int>& nums, int maxOperations, int mid){
        int opr = 0;
        for(int i = 0; i < nums.size(); i++){
            opr = nums[i]/mid;
            if(nums[i]%mid == 0)
                opr--;
            maxOperations -= opr;
            if(maxOperations < 0)
                return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1, end = INT_MIN, mid, ans;
        for(int i = 0; i < nums.size(); i++){
            if(end < nums[i])
                end = nums[i];
        }
        
        while(start <= end){
            mid = start + (end - start)/2;
            if(possiblePenalty(nums, maxOperations, mid)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return start;
    }
};