class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int iteration = mat[0].size()+ mat.size() -1;
        vector<int> result;
        for(int i=0; i<iteration; ++i){
            int p = result.size();
            for(int j=0;j<mat.size();j++){
                for(int k=0; k<mat[0].size();k++)
                {
                    if(j+k==i)
                        result.emplace_back(mat[j][k]);
                }
            }
            if(i%2==0)
                reverse(result.begin()+p,result.end());
        }
        
        return result;
    }
};