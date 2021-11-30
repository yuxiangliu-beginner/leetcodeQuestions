class Solution {
private:
        void buildHeightGrid(vector<vector<char>> matrix, vector<vector<int>> & heightGrid)
        {
            for(int j =0;j < matrix[0].size(); j++)
            {
                heightGrid[0][j] = (matrix[0][j]=='1'?1:0);
            }
            for(int i = 1; i < matrix.size();i++)
            {
                for(int j = 0; j < matrix[i].size();j++)
                {
                    heightGrid[i][j] = (matrix[i][j]=='1'? heightGrid[i-1][j]+1 : 0);
                }
            }
        }
        int findArea(vector<int> & heightGrid)
        {
            int currColumnCount = heightGrid.size();
            
            int maxHeight = -1;
            stack<int> indexStack;
            indexStack.push(-1);
            for(int i=0 ; i < currColumnCount; i++ )
            {
                while(indexStack.top()!=-1 && heightGrid[indexStack.top()]>=heightGrid[i])
                {
                    int currHeight = indexStack.top();
                    indexStack.pop();
                    int prevIndex = indexStack.top();
                    maxHeight = max(maxHeight,heightGrid[currHeight]*(i-prevIndex-1));
                }
                indexStack.push(i);
            }
            while(indexStack.top()!=-1)
            {
                int currHeight = indexStack.top();
                indexStack.pop();
                int prevIndex =indexStack.top();
                maxHeight = max(maxHeight,heightGrid[currHeight]*(currColumnCount-prevIndex-1));
            }
            return maxHeight;
        }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows =matrix.size();
       
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        vector<vector<int>> heightGrid(rows,vector<int>(cols,-1));
        buildHeightGrid(matrix,heightGrid);
        
        // for(int i =0; i < rows;i++)
        // {
        //     for(int j =0; j <cols;j++)
        //     {
        //         cout<<heightGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxArea = -1;
        for(int i =0 ; i < rows;i++)
        {
            int cur = findArea(heightGrid[i]);
            maxArea = max(maxArea, cur);
        }
        return maxArea;
    }
};