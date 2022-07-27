class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        int firstPosition = position[0], count = 1;
        
        for(int i = 1; i < position.size(); i++){
            if(position[i] - firstPosition >= mid){
                firstPosition = position[i];
                count++;
            }
            
            if(count == m)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1, end = position[size(position)- 1] - position[0], mid, ans = -1;
        
        while(start <= end){
            mid = start + (end - start)/2;
            
            if(isPossible(position, m, mid)){
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};