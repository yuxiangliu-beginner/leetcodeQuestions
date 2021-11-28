class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>  & graph, vector<int> & path,int node)
    {
        if(node == graph.size()-1)
        {
            res.push_back(path);
            return;
        }
        
        for(auto g : graph[node])
        {
            path.push_back(g);
            dfs(graph,path,g);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0)
            return {};
        vector<int> path;
        path.push_back(0);
        int node = 0;
        dfs(graph, path , node);
        return res;
    }
};