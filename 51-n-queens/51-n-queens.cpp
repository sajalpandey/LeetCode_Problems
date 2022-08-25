class Solution {
public:
    void placeQueens(int i, vector<vector<string>> &ans, int n, vector<vector<char>> &board,vector<char>&up,vector<char>&leftDig, vector<char>& ritDig)
    {   
        if(i >= n){
            vector<string> res;
            for(int x = 0; x < n; x++){
                string temp="";
                for(int y=0; y < n ;y++)
                    temp+= board[x][y];
                res.push_back(temp);
            }
            ans.push_back(res);
            return ;
        }
        for(int j=0; j<n; j++){
            if(up[j] == '.' && leftDig[i-j+n-1] == '.' && ritDig[i+j] == '.'){
                board[i][j] = 'Q';
                up[j] = '#', leftDig[i-j+n-1] = '#', ritDig[i+j] = '#';
                placeQueens(i+1, ans, n, board, up, leftDig, ritDig);
                board[i][j] = '.';
                up[j] = '.', leftDig[i-j+n-1] = '.', ritDig[i+j] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<char> up(n,'.') , leftDig(2*n,'.'), ritDig(2*n,'.');
        placeQueens(0, ans, n, board, up, leftDig, ritDig);
        return ans;
    }
};