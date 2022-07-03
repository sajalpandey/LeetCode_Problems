class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        1. for each new sorted string insert into map and assign a counter number
        2. if the string is new again repeat above step
        3. if the string is repeated then find th unique index from map 
        4. based on that unique index append to the result vector
        5. return the result vector
        */
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ump;
        string temp = "";
        for(auto & str : strs){
            temp = str;
            sort(str.begin(),str.end());
            ump[str].emplace_back(temp);
        }
        
        for(auto & value : ump)
            result.emplace_back(value.second);
        
        return result;
    }
};