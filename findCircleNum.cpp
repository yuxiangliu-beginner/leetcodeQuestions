class Solution {
public:
    // vector<set<int>>  table;
    // void checkTable (vector<vector<int>>& isConnected,int i,int j)
    // {
    //     if(i<0||i>=isConnected.size() ||j <0 || j>=isConnected.size() || isConnected[i][j]==0)
    //         return false;
    //     for(auto t :table)
    //     {
    //         if(t.count(isConnected[i][j])!=0)
    //             return false;
    //     }
    //     set<int> s;
    //     s.insert(isConnected[i][j]);
    //     table.push_back(s);
    //     checkTable(isConnected,i-1,j);
    //     checkTable(isConnected,i+1,j);
    //     checkTable(isConnected,i,j-1);
    //     checkTable(isConnected,i,j+1);
    // }
    void helper(vector<vector<int>>& M, int k, vector<bool>& visited)
    {
        visited[k]=true;
        for(int i = 0 ; i < M.size();i++)
        {
            if(!M[k][i] || visited[i])
                continue;
            helper(M,i,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //union find
        //bfs+vector<set> n^2+n
        // int len = isConnected.size();
        // for(int i = 0;i < len;i++)
        // {
        //     for(int j = 0 ; j <len;j++)
        //     {
        //         checkTable(isConnected,i,j);
        //     }
        // }
        // return table.size();
        
        int n = isConnected.size();
        int ans = 0 ;
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(visited[i])
                continue;
            helper(isConnected,i,visited);
            ans++;
        }
        return ans;
    }
};