class Solution {
public:
//     int helper(vector<vector<int>>& grid,int row,int col)
//     {
//         if(row<0|| row >= grid.size() || col<0 || col >=grid[0].size() || grid[row][col]==0)
//             return 0;
        
//         grid[row][col] = 0;
        
//         return 1+helper(grid,row-1,col)+
//              helper(grid,row+1,col)+
//              helper(grid,row,col-1)+
//              helper(grid,row,col+1);
            
//     }
    
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int result = 0 ;
//         for(int i = 0 ;i < grid.size(); i++)
//         {
//             for(int j = 0; j < grid[0].size();j++)
//             {
               
//                 if(grid[i][j]==1)
//                 {
//                     result = max(result,helper(grid,i,j));
//                 }
//             }
//         }
//         return result;
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int helper(vector<vector<int>>& grid, int row, int col)
    {
        if(row< 0 || row>=grid.size()|| col< 0 || col>=grid[0].size()|| grid[row][col]==0 )   
            return 0;
        grid[row][col] = 0;
        return 1+ helper(grid,row-1,col)
            + helper(grid,row+1,col)
            + helper(grid,row,col-1)
            + helper(grid,row,col+1);
    }
    
    
    
    
    
    
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0 ; i < grid.size();i++)
        {
            for(int j = 0 ; j < grid[0].size();j++)
            {
                result = max(result, helper(grid, i,j));
            }
        }
        return result;
    }
    
    
    
    
    

};