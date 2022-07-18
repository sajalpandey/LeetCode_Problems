class Solution {
public:
    int distance(vector<int> x, vector<int> y){
        return ((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> ump;
        ump.insert(distance(p1 , p2));
        ump.insert(distance(p1 , p3));
        ump.insert(distance(p1 , p4));
        ump.insert(distance(p2 , p3));
        ump.insert(distance(p2 , p4));
        ump.insert(distance(p3 , p4));
        
        if (ump.size() == 2 && !ump.count(0))
            return true;
        return false;
    }
};