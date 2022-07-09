class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row =  mat.size(), col = mat[0].size();
        vector<int> result ;
        int dir = 0;
        result.emplace_back(mat[0][0]);
        
        int i = 0, j = 0;
        while(i != row-1 || j != col -1)
        {
            if(dir == 0){
                if(j == col - 1)
                    i++ , dir = 1;
                else if (i == 0)
                    j++, dir = 1;
                else
                    i-- , j++;
            }
            else{
                if(i == row -1)
                    j++, dir = 0;
                else if (j == 0)
                    i++ , dir = 0;
                else
                    i++ , j--;
            }
            
            result.emplace_back(mat[i][j]);
        }
        return result;
    }
};