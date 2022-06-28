class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i=0, j=height.size()-1;
        while(i<j){
            int tempArea = min(height[i],height[j]) * abs(i-j);
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