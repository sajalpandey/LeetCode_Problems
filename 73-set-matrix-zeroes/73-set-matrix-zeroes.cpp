class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstRow = 0 , firstCol = 0;
        int row = matrix.size(), col = matrix[0].size();
        //check for 1st Row
        for(int i = 0; i< col; i++)
            if(matrix[0][i]==0){
                firstRow = 1;break;
            }
        //check for 1st Col
        for(int j = 0; j<row; j++)
            if(matrix[j][0] == 0){
                firstCol = 1;break;
            }
        
        //Store IF any ele is zero Strore it in first row and column
        
        for(int i=1; i<row; i++)
        {
            for(int j=1; j<col; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
    
        if(firstRow)
        {
            for(int i =0 ;i<col; i++)
                matrix[0][i] = 0;
        }

        if(firstCol)
        {
            for(int j=0;j<row;j++)
                matrix[j][0] =0;
        }
        
    }
};