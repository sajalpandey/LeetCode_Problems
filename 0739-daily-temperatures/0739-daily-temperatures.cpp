class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> numberofDays(n);
        stack<int> nextGreater;
        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            if(!nextGreater.empty() && temperatures[nextGreater.top()] > temperatures[i])
            {
                numberofDays[i] = nextGreater.top() - i;
                nextGreater.push(i);
            }
            else if(!nextGreater.empty() && temperatures[i] >= temperatures[nextGreater.top()])
            {
                while(!nextGreater.empty() && temperatures[i] >= temperatures[nextGreater.top()])
                {
                    nextGreater.pop();
                }
                if(nextGreater.empty())
                {
                    numberofDays[i] = 0;
                    nextGreater.push(i);
                }
                else
                {
                    numberofDays[i] = nextGreater.top() - i;
                    nextGreater.push(i);
                }  
            }
            else
            {
                numberofDays[i] = 0;
                nextGreater.push(i);
            }
        }
        return numberofDays;
    }
};