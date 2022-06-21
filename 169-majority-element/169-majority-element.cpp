class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum=1,ele=nums[0];
        for(int i=1;i<nums.size();++i){
            if(sum == 0){
                ++sum;
                ele=nums[i];
            }
            else if(ele==nums[i])
                ++sum;
            else{
                --sum;  
            }
        }
        return ele;
    }
};