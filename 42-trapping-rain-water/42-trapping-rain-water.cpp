class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<2)
            return 0;
        int res=0,lmax=0,rmax=0,i=0,j=n-1;
        while(i<j){
            
            if(height[i]<height[j]){
                if(lmax<height[i])
                    lmax = height[i];
                res += lmax-height[i++];
            }
            else{
                if(rmax<height[j])
                    rmax = height[j];
                res += rmax-height[j--];
            }
        }
        return res;
    }
};   