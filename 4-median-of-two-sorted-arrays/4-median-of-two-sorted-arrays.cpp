class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int start = 0, end = nums1.size(), mid;
        int maxLeftX, maxLeftY, minRightX, minRightY;
        int parX, parY;
        while(start <= end){
            mid = start + (end - start)/2;
            int parX = mid;
            parY = (size(nums1) + size(nums2) + 1)/2 - parX;
            
            maxLeftX = (parX == 0) ? INT_MIN : nums1[parX - 1];
            minRightX = (parX == nums1.size()) ? INT_MAX : nums1[parX];
            
            maxLeftY = (parY == 0) ? INT_MIN : nums2[parY - 1];
            minRightY = (parY == nums2.size()) ? INT_MAX : nums2[parY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                //odd Case
                if((nums1.size() + nums2.size()) % 2 != 0)
                    return (max(maxLeftX, maxLeftY));
                else
                    return ((double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2);
            }
            
            else if(maxLeftX > minRightY)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return 0;
    }
};