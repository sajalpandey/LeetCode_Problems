class Solution {
public:
    int find(int x, int l, int h){
        while(l<=h){
            int mid = l + (h - l)/2;
            if(mid == x/mid)
                return mid ;
            else if (mid > x/mid)
                h = mid - 1;
            else if (mid < x/mid && (mid + 1) > x/(mid + 1))
                return mid;
            else 
                l = mid + 1;
        }
        return 1;
    }
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        return find(x, 1, x/2);
    }
};