class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i=0, j=height.size()-1,tempArea;
        while(i<j){
            tempArea = min(height[i],height[j]) * (j-i);
            if(tempArea > maxArea)
                maxArea = tempArea;
            if(height[i]<height[j])
                ++i;
            else
                --j;
        }
        return maxArea;
        
    }
};