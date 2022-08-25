class Solution {
public:
    bool safePlace(int i, int j, vector<vector<char>> &board, int n){
        int corX = i;
        while(corX >= 0){
            if(board[corX][j] == 'Q')
                return false;
            corX--;
        }
        corX = i;
        int corY = j;
        while(corX>=0 && corY>=0){
            if(board[corX][corY] == 'Q')
                return false;
            corX--; corY--;
        }
        corX=i, corY=j;
        while(corX >= 0 && corY < n){
            if(board[corX][corY] == 'Q')
                return false;
            corX--;corY++;
        }
        return true;
    }
    void placeQueens(int i, vector<vector<string>> &ans, int n, vector<vector<char>> &board)
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
            if(safePlace(i, j, board, n)){
                board[i][j] = 'Q';
                placeQueens(i+1, ans, n, board);
                board[i][j] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        placeQueens(0, ans, n, board);
        return ans;
    }
};