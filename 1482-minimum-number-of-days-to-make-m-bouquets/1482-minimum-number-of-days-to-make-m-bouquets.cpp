class Solution {
public:
    int BouquetsPossible(vector<int>& bloomDay, int m, int k, int mid){
        
        int boq = 0, count = 0;
        for(int i = 0; i < size(bloomDay); i++){
            if(bloomDay[i] <= mid)
                count++;
            else
                count = 0;
            if(count == k){
                boq++;
                count = 0;
            }
            
        }
        return boq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = size(bloomDay);
        if(n < m*k)
            return -1;
        
        int start = INT_MAX, end = INT_MIN, mid, ans;
        for(int i = 0; i < n; i++){
            if(start > bloomDay[i])
                start = bloomDay[i];
            if(end < bloomDay[i])
                end = bloomDay[i];
        }
        while(start <= end){
            mid = start + (end - start)/2;
            int temp = BouquetsPossible(bloomDay, m, k, mid);
            if(temp >= m){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};