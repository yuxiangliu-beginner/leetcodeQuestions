// class Solution {
// public:
//     void Dfs(vector<vector<char>> & board, int i ,int j ,int n, int m)
//     {
//         if(i<0 || i >= n || j <0 || j >= m || board[i][j] !='O')
//             return;
        
//         board[i][j] = '#';
        
//         Dfs(board, i -1, j, n,m);
//         Dfs(board, i +1, j, n,m);
//         Dfs(board, i, j-1, n,m);
//         Dfs(board, i, j+1, n,m);
        
//     }
//     void solve(vector<vector<char>>& board) {
//         int n  = board.size();
//         if(n == 0)
//              return;
        
//         int m = board[0].size();
        
        
        
//         //checking first and last column
//         for(int i = 0; i < n; i ++)
//         {
//             if(board[i][0]=='O')
//             {
//                 Dfs(board, i , 0, n,m );
//             }
//             if(board[i][m-1]=='O')
//             {
//                 Dfs(board,i, m-1, n,m);
//             }
            
//         }
        
//         //check first and last row
//         for(int j = 0 ; j < m ; j++)
//         {
//             if(board[0][j]=='O')
//                 Dfs(board, 0,j,n,m);
//             if(board[n-1][j]=='O')
//                 Dfs(board,n-1,j,n,m);
//         }
    
        
//         //loop the board if it is #, change back to O
//         //if it is O, change to X;
//         for(int i = 0 ; i<n;i++)
//         {
//             for(int j = 0; j < m ; j++)
//             {
//                 if(board[i][j]=='O')
//                     board[i][j] = 'X';
//                 if(board[i][j]=='#')
//                     board[i][j] = 'O';
//             }
//         }
        
        
//     }
// };


class Solution {
public:
    void Dfs(vector<vector<char>> & board, int i ,int j ,int n, int m)
    {
        if(i<0||j<0||i>=n||j>=m||board[i][j] !='O')
            return;
        board[i][j] = '#';
        Dfs(board,i-1,j,n,m);
        Dfs(board,i+1,j,n,m);
        Dfs(board,i,j-1,n,m);
        Dfs(board,i,j+1,n,m);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0)
            return;
        int m = board[0].size();
        if(n < 2 || m < 2)
            return;
        
        for(int i = 0 ; i < n; i ++)
        {
           if(board[i][0] == 'O')
               Dfs(board, i , 0, n,m);
            if(board[i][m-1]=='O')
                Dfs(board,i,m-1,n,m);
        }
        
        
        
        for(int j = 0; j < m ; j++)
        {
            if(board[0][j]=='O')
                Dfs(board,0,j,n,m);
            if(board[n-1][j]=='O')
                Dfs(board,n-1,j,n,m);
        }
        
        
        for(int i = 0 ;i <n;i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                
                if(board[i][j]=='#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
                // if(board[i][j] == 'O')
                //     board[i][j] = 'X';
                // if(board[i][j]=='#')
                //     board[i][j] = 'O';
            }
        }
        
        
        
    }
};