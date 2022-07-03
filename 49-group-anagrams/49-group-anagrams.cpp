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
        vector<vector<string>> result(10000);
        unordered_map<string, int> ump;
        int counter = 1;
        for(auto str : strs){
            string temp = str;
            sort(str.begin(),str.end());
            if(ump.find(str)==ump.end())
                ump[str] = counter++;
            result[ump[str]-1].emplace_back(temp);  
        }
        result.resize(counter-1);
        return result;
    }
};