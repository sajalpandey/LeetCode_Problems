class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        vector<int> rmax(height.size(),0);
        int temp=height[height.size()-1],res=0;
        for(int i=height.size()-1;i>=0;i--){
            if(temp<height[i]){
                temp=height[i];
            }
            rmax[i]=temp;
        }
        temp=height[0];
        for(int i=0;i<height.size();i++){
            if(temp<height[i])
                temp=height[i];
            res += (min(temp,rmax[i]) - height[i]);
        }
        return res;
    }
};   