class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort(courses.begin(), courses.end(),[](auto &a, auto &b){return a[1]>b[1];} );
//         sort(courses.begin(), courses.end(), [](auto &a, auto &b) {return a[1] < b[1];});
//         priority_queue<int> pq;
//         int total =0;
        
//         for(auto & c: courses)
//         {
//             int dur = c[0];
//             int end = c[1];
            
//             if(total+ dur <= end)
//             {
//                 total+= dur;
//                 pq.push(dur);
                
//             }
//             else if(pq.size() && pq.top() > dur)
//             {
//                 total = total + (dur - pq.top());
//                 pq.pop();
//                 pq.push(dur);
//             }
            
//         }
//         return pq.size();
        
        
        sort(courses.begin() , courses.end(), [](auto &a, auto &b){return a[1]< b[1];});
        priority_queue<int> pq;
        
        int total = 0;
        for(auto &c : courses)
        {
            int dur = c[0];
            int last = c[1];
            
            
            if(last>= dur+total)
            {
                total += dur;
                pq.push(dur);
            }
            //find preve dur that spending more time than the current.
            //pop it, and push into th pq;
            else if(pq.size() && pq.top() > dur)
            {
                total = total + (dur - pq.top());
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};