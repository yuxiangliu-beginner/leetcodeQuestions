class Solution {
// struct T{
//   int   
// };
typedef pair<int, int> course;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                
//         if(prerequisites.size()==1)
//             return true;
//         priority_queue<course, vector<course>, greater<course>>pq;

//         for(auto p:prerequisites)
//         {
//             pq.push(make_pair(p[1],p[0]));
//         }
//         int n = pq.size()+1;
//         set<int> table;
//         table.insert(0);
//         // cout<<pq.empty()<<endl;
//         // table.insert()
        
//         while(!pq.empty())
//         {
            
//             course c = pq.top();
//             cout<<c.first<<" "<<c.second<<endl;
//             if(table.count(c.first)<0)
//                 return false;
         
            
//             table.insert(c.second);
//             pq.pop();
//         }
//         cout<<table.size()<<" "<<n<<endl;
//         return table.size()==n;
        
        vector<vector<int>> G(numCourses);
        vector<int> degree(numCourses,0),bfs;
        
        // push the node to graph
        // vector[prerequisites] : course1, course2;
        // degree[course]++;
        for(auto & e :prerequisites)
        {
            G[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        
        //for note degree == 0, it must be a init start in bfs.
        for(int i = 0; i < numCourses;i++)
        {
            if(!degree[i])
            {
                bfs.push_back(i);
            }
        }
        
        //loop bfs.
        //check every course, if the degree is 0, then it can be use as a prerequisite
        for(int i =0 ; i < bfs.size(); i++)
        {
            for(int j : G[bfs[i]])
            {
                if(--degree[j] == 0)
                    bfs.push_back(j);
            }
        }
        //check the size.
        return bfs.size() == numCourses;
    }
};