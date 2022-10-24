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
    vector<int> nextSmaller(vector<int>& heights, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while(st.top()!=-1 && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int> & heights, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(st.top()!=-1 && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        return largestHisto(heights);
        int n = heights.size();
        vector<int> leftSmaller(n);
        leftSmaller = prevSmaller(heights, n);
        
        vector<int> rightSmaller(n);
        rightSmaller = nextSmaller(heights, n);
        
        int maxArea = INT_MIN, newArea;
        for(int i = 0 ; i < n ; i++){
            if(rightSmaller[i] == -1)
                rightSmaller[i] = n;
            newArea = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
};

/*Algo

0) Create a prev smaller elements array
1) Create a next smaller elements array 
2) Max area rectangle for any index will be height_of_current_index * abs(left smaller index - right smaller index)

*/