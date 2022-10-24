class Solution {
public:
    int largestHisto(vector<int>& heights)
    {
        int maxArea = 0, n = heights.size();
        stack<int> st;
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int h = heights[st.top()]; st.pop();
                int l;
                if(st.empty())
                    l = i;
                else
                    l = i - st.top() - 1;
                maxArea = max(maxArea, h*l);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(col,0);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]+=1;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea , largestHisto(heights));
        }
        return maxArea;
    }
};

/*Algorithm
1. For each row , take this as seprate building like histogram
2. Now each successive row add values from row so building can be formed
3. Now calculate largestAreaHistogram for each row
4. Find max of all calculated areas.
*/