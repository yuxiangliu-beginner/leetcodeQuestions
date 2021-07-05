class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r,(vector<int>(c,0)));
        
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c)
            return mat;
        int index = 0;
        for(int i = 0 ; i < m; i++ )
        {
            for(int j = 0 ; j < n ; j++)
            {
                // cout<<index<<" "<<c<<" "<<index/c<<" "<<r<<" "<<index%c<<endl;
                res[index/c][index%c]=mat[i][j];
                index = index+1;
            }
        }
        return res;
    }
};