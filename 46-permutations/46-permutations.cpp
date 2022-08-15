class Solution {
public:
    /**
    At every position there will be n number of choices
    select any number from array and place it on the 0th position 
    which means swap ele at 0th position to ele at pth position
    
    now call recursion to do remaining task
    */
    void generatePermutation(int pos, vector<int>& nums, vector<vector<int>>& ans){
        
        if(pos >= nums.size()){
            ans.push_back(nums);
        }
        for(int i = pos; i<nums.size(); i++){
            swap(nums[i],nums[pos]);
            generatePermutation(pos+1, nums, ans);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermutation(0, nums, ans);
        return ans;
    }
};