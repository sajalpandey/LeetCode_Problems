class Solution {
public:
    bool bSearch(vector<vector<int>>& matrix, int target, int findRow){
        int start = 0 , end = size(matrix[findRow]) -1, mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(matrix[findRow][mid] == target)
                return true;
            else if(matrix[findRow][mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = size(matrix), column = size(matrix[0]), findRow=0;
        for(int j = 0; j < rows; j++){
            if(target <= matrix[j][column-1]){
                findRow = j;
                break;
            }
        }
        
        cout<<findRow<<endl;
        if(bSearch(matrix, target, findRow))
            return true;
        return false;
    }
};