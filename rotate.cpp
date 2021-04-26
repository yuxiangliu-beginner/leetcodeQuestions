class Solution {
public:
    
    void transposed(vector<vector<int>>& matrix)
    {
            int n = matrix.size();
            for(int i = 0; i < n ;i++)
            {
                for(int j = i ; j<n;j++)
                {
                    int tmp = matrix[j][i];
                    matrix[j][i] = matrix[i][j];
                    matrix[i][j] = tmp;

                }
            }
    }
    void reversed(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i = 0 ; i <n;i++)
        {
            for(int j = 0 ; j < n/2 ; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] =  matrix[i][n-j-1];
                matrix[i][n-j-1]= tmp;

            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        //rotated = transposed + reversed
        
        //brute foce O(n^2)
        //it i as the outside to inside. j as the number of elements
        // int n = matrix.size();
        // for(int i = 0; i < (n+1)/2; i++)
        // {
        //     for(int j = 0 ; j < (n/2) ; j++)
        //     {
        //         int tmp = matrix[n-1-j][i];
        //          matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        //         matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
        //         matrix[j][n - 1 - i] = matrix[i][j];
        //         matrix[i][j] = tmp;
        //     }
        // }
        
        
        //for better understanding , transposed+reversed is more understandable
        transposed(matrix);
        reversed(matrix);
    }
};