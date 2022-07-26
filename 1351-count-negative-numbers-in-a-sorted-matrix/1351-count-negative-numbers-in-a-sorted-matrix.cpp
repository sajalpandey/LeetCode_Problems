class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), count = 0;
        int i = column - 1;
        int j = 0;
        
        while(i >= 0 && j < row){
            if(grid[j][i] >= 0){
                count += column - 1 - i;
                j++;
            }
            else{
                i--;
            }
        }
        
        count += (row - j) * (column);
        return count;
    }
};