class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)
            return;
        vector<int> res;
        int maxClosest = nums.size()-1 , i=nums.size()-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                while(maxClosest>i && nums[maxClosest]<=nums[i])
                    maxClosest--;
                swap(nums[i],nums[maxClosest]);
                i++;
                int j = nums.size()-1;
                //cout<<i<<" "<<j<<endl;
                while(i<j)
                    swap(nums[i++],nums[j--]);
                return;
            }
            --i;
        }
        return reverse(nums.begin(),nums.end());
    }
};