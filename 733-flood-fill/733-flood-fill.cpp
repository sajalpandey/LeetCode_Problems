class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int color, int row, int col,int val)
    {
        //base case
        if(sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] == color || image[sr][sc]!=val){
            return;
        }
        image[sr][sc] = color;
        floodFillHelper(image, sr-1, sc, color, row, col,val);
        floodFillHelper(image, sr, sc+1, color, row, col,val);
        floodFillHelper(image, sr+1, sc, color, row, col,val);
        floodFillHelper(image, sr, sc-1, color, row, col,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)    {
        int col = image[0].size(), row = image.size();
        int val = image[sr][sc];
        floodFillHelper(image, sr, sc, color,row, col, val);
        return image;
    }
};