class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st ,pt;
        int n = arr.size();long long minSum = 0;
        vector<int> prevGreater(n) , nextGreater(n);
        //Calculate next Smaller ele
        for(int i = arr.size()-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(i);
                nextGreater[i] = arr.size() - 1 -i;
            }
            else
            {
                nextGreater[i] = st.top() -i -1;
                st.push(i);
            }
        }
        //Calculate prev Smaller element
        for(int i = 0; i < arr.size(); i++)
        {
            while(!pt.empty() && arr[pt.top()] >= arr[i])
                pt.pop();
            if(pt.empty())  
            {
                pt.push(i);
                prevGreater[i] = i;
            }
            else
            {
                prevGreater[i] = i - pt.top() -1;
                pt.push(i);
            }
        }
        
        //For Every ele contribution in sum of subarray min will be
        // prevSmallerEle * nextSmallerEle * arr[i]
        int mod = 1000000007;
        for(int i = 0; i < n; i++)
        {
            long long temp = ((prevGreater[i]+1)*(nextGreater[i]+1)) % mod;
            temp = (temp*arr[i])%mod;
            minSum = (minSum + temp)%mod;
        }
        return minSum;
    }
};