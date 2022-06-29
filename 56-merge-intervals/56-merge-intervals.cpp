class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;vector<int> temp;
        sort(intervals.begin(),intervals.end());
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1; i< intervals.size();i++){
            if(intervals[i][0]<=res[res.size()-1][1]){
                if(intervals[i][1]>res[res.size()-1][1]){
                    temp.emplace_back(res[res.size()-1][0]);
                    temp.emplace_back(intervals[i][1]);
                    res.pop_back();
                    res.emplace_back(temp);
                    temp.clear();
                }
            }
            else
                res.emplace_back(intervals[i]);
        }
        return res;
    }
};