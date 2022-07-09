class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int s = 0, r = 0 ,row = matrix.size() , col = matrix[0].size();
        vector<int> result;
        int i = 0, j = 0;
        while(1)
        {
            i = s, j = r;
            // Right Movement
            while(j<col)
                result.emplace_back(matrix[i][j++]);
            col--;
            j--;i++;
            
            //Down Movement
            while(i<row)
                result.emplace_back(matrix[i++][j]);
            row--;
            i--;
            --j;
            if(size(result) == matrix.size()*matrix[0].size())
                break;
            
            //Left Movement
            while(j>=r)
                result.emplace_back(matrix[i][j--]);
            r++;
            j++;
            i--;
            //Up Movement
            while(i>s)
                result.emplace_back(matrix[i--][j]);
            s++;
            if(size(result) == matrix.size()*matrix[0].size())
                break;
        }
        
        return result;
    }
};