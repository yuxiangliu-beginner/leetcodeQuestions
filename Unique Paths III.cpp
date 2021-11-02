// https://leetcode.com/problems/unique-paths-iii/discuss/1553805/C%2B%2B-Simple-and-Clean-DFS-Solution-Explained-0ms-Faster-than-100
// class Solution {
// public:
//     int empty  =1 ;
//     int res = 0;
    
//     void dfs(vector<vector<int>> & grid ,int x ,int y , int count)
//     {
//         if(x < 0 || y <0 || x >=grid.size() || y >= grid[0].size() || grid[x][y] == -1)
//             return;
        
        
//         if(grid[x][y] == 2)
//         {
//             if(empty == count)
//                 res++;
//             return;
//         }
        
        
//         grid[x][y] = -1;
//         dfs(grid,x+1,y,count+1);
//         dfs(grid,x-1,y,count+1);
//         dfs(grid,x,y+1,count+1);
//         dfs(grid,x,y-1,count+1);
        
        
//         grid[x][y] = 0;
//     }
    
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int start_x, start_y;
        
        
//         for(int i = 0 ; i < grid.size(); i++)
//         {
//             for(int j = 0 ; j < grid[0].size(); j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     start_x = i;
//                     start_y = j;
//                 }
//                 else if(grid[i][j] == 0)
//                 {
//                     empty++;
//                 }
//             }
//         }
//         dfs(grid, start_x,start_y,0);
//         return res;
//     }
// };


class Solution {
public:
    
    // the empty = 1 because the from start point to end point will be count (path + end point) = count ;
    int empty  = 1 ;
    int res = 0;
    
    void dfs(vector<vector<int>> & grid ,int x ,int y , int count)
    {
        if(x < 0 || y <0 || x >=grid.size() || y >= grid[0].size() || grid[x][y] == -1)
            return;
        
        if(grid[x][y] == 2)
        {
            if(count == empty)
                res++;
            return;
        }
        grid[x][y]  = -1;
        
        dfs(grid,x+1,y,count+1);
        dfs(grid,x-1,y,count+1);
        dfs(grid,x,y+1,count+1);    
        dfs(grid,x,y-1,count+1);
        
        grid[x][y] = 0;
    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x,start_y;
        
        for(int i = 0 ;i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    start_x = i ;
                    start_y = j ;
                }
                else if(grid[i][j] == 0)
                {
                    empty++;
                }
            }
            
        }
        dfs(grid,start_x,start_y, 0);
        return res;
    }
};