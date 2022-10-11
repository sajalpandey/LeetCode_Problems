class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> characters;
        for(auto &ch : s)
        {
            if(!characters.empty() && characters.back().first == ch)
            {
                ++characters.back().second;
            }
            else
                characters.push_back({ch,1});
            if(characters.back().second == k)
                characters.pop_back();
        }
        s = "";
        for(auto &p : characters)
        {
            while(p.second-- > 0)
            s+= p.first;       
        }
        return s;
    }
};