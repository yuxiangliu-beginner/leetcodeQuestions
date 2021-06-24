class Solution {
public:
    vector<vector<int>> seen;
    int dfsHelper(vector<vector<int>>& m,int i, int j,int pre)
    {
        
        if(i<0 || i >=m.size()|| j < 0 || j >=m[0].size()){
             return 0;
        }
        // cout<<i<<" "<<j<<endl;
           
//         if(m[i][j] <= pre || seen[i][j]==1)
//             return 0;
        
        
        // int left,right,up,down
        if(m[i][j]>pre)
        {
            //if searched before, we do not want search it again
            //we simpliy add its value to path
            if(seen[i][j]!=0)
                return seen[i][j];
            
            
            int left = dfsHelper(m,i-1,j,m[i][j])+1;
            int right = dfsHelper(m,i+1,j,m[i][j])+1;
            int up = dfsHelper(m,i,j-1,m[i][j])+1;
            int down = dfsHelper(m,i,j+1,m[i][j])+1;
            
            seen[i][j]= max(max(left,right),max(up,down));  
            return max(max(left,right),max(up,down));  
        }
        return 0;
    }
//     int dfs(vector<vector<int>>& m,int i, int j)
//     {
        
//         seen[i][j] =1;
//         // return 1;
//         int left = dfsHelper(m,i-1,j,m[i][j]);
//         int right = dfsHelper(m,i+1,j,m[i][j]);
//         int up = dfsHelper(m,i,j-1,m[i][j]);
//         int down = dfsHelper(m,i,j+1,m[i][j]);
        
//         seen[i][j] =0;
//         return max(max(left,right),max(up,down))+1;
//     }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            seen.push_back(vector<int>(matrix[0].size(),0));
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size();j++)
            {
                // ans = dfs()
                int cur = dfsHelper(matrix,i,j,INT_MIN);
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};