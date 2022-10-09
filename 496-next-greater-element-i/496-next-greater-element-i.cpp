class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int mn = -1;
        stack<int> st;
        vector<int> ans;
        for(int i = nums2.size()-1; i >= 0; i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else
            {
                while(!st.empty()){
                    if(st.top() > nums2[i])
                        break;
                    st.pop();
                }
                if(st.empty()){
                    mp[nums2[i]] = -1;
                }
                else
                    mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(auto &e: nums1)
            ans.push_back(mp[e]);
        return ans;
    }
};