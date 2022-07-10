class Solution {
public:
    bool searchWord(vector<vector<char>>& board, int i, int j, int count, string word){
        
        
        if(count == word.size())
            return true;
        if(i<0 || i>= board.size() || j<0 || j>=board[i].size() || board[i][j] != word[count])
            return false;
        
        board[i][j] = ' ';
        
        bool adjacentSearchResult  = searchWord(board, i+1, j, count+1, word)
                                    || searchWord(board, i-1, j, count+1, word)
                                    || searchWord(board, i, j+1, count+1, word)
                                    || searchWord(board, i, j-1, count+1, word);
        
        board[i][j] = word[count];
        return adjacentSearchResult;
                                                                         
    }
    bool exist(vector<vector<char>>& board, string word) {
        // Simple DFS Solution
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && searchWord(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};