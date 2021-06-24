class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //create a graph
        vector<vector<int>> G(numCourses);
        vector<int> degree(numCourses,0), bfs;
        //insert element to the graph
        for(auto & e : prerequisites)
        {
            G[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        
        // vector<int> ans;
        //find the bfs init point(degree[i]==0)
        for(int i =0 ; i < numCourses; i++)
        {
            if(!degree[i])
            {
                bfs.push_back(i);
            }
        }
        

        //using bfs size to check it 
        //if degree ==0 push to bfs.
        // for everytime reduce j , push to ans;
        for(int i = 0 ; i < bfs.size(); i++)
        {
            for(int j : G[bfs[i]])
            {
                if(--degree[j]==0)
                    bfs.push_back(j);
            }
        }
        if(bfs.size()!=numCourses)
            return {};
        
        return bfs;
    }
};