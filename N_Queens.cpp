class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        vector<string> board;
        string s;
        for(int i = 0;i < n; i ++)
        {
            s+='.';
        }
        for(int i = 0 ; i < n; i++)
        {
            board.push_back(s);
        }
        recurse(0,n,board);
        return ans;
    } 
    void recurse(int col,int size,vector<string> board)
    {
        if(col == size)
            ans++;
        for(int i = 0; i < size; i++)
        {
            if(isValid(board,i,col,size))
            {
                board[i][col]='Q';
                recurse(col+1,size,board);
                board[i][col]='.';
            }
        }
        
    }
    bool isValid(vector<string> board,int row, int col, int size)
    {
        for(int i = 0; i < col ;i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--)
            if(board[i][j]=='Q')
                return false;
        for(int i = row+1,j= col-1;i <size&&j>=0;i++,j--)
            if(board[i][j]=='Q')
                return false;
        
        return true;
    }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<string> board;
//         string s;
//         for(int i = 0; i < n ; i++)
//         {
//             s+=".";
//         }
//         for(int i = 0 ; i < n ; i++)
//         {
//             board.push_back(s);
//         }
//         recurse(0,n,board);
//         return ans;

//     }
//     void recurse(int col,int size,vector<string> board)
//     {
//         if(col == size)
//         {
//             ans++;
            
//         }
            
//         for(int i = 0 ; i < size;i++)
//         {
//             if(isValid(board,i,col,size))
//             {
//                 board[i][col] = 'Q';
//                 recurse(col+1,size,board);
//                 board[i][col] = '.';
//             }
//         }
//     }
//     bool isValid(vector<string> board,int row,int col, int n)
//     {
//         //check current column
//         for(int i = 0; i <col;i++)
//         {
//             if(board[row][i]=='Q')
//             {
//                 return false;
//             }
//         }
//         //check diagonal line 
//         // 1                            1
//         //     1                    1
//         //         1            1
//         //             current
//         //         1
//         //     1
//         // 1    check another diagonal line 
//         for(int i = row-1, j = col-1; i >=0 && j >=0 ; i--, j--)
//         {
//             if(board[i][j]=='Q')
//                 return false;
//         }
//          //check another diagonal line 
//         for(int i = row+1,j = col-1;i <n && j >= 0;i++,j--)
//         {
//             if(board[i][j]=='Q')
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
};