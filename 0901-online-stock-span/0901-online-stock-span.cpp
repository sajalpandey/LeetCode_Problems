class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count;
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        count++;
        //cout<<count<<endl;
        if(!st.empty() && st.top().first > price)
        {
            st.push({price,count});
            return 1;
        }
        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        if(st.empty())
        {
            st.push({price,count});
            return count;
        }
        auto p = st.top();
        //st.pop();
        //cout<<"p = "<<(count - p.second)<<endl;
        st.push({price, count});
        return (count-p.second);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */