// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85222/C%2B%2B-priority-queue-solution-O(klogn)




struct CompareFirstIndex {
    bool operator()(pair<int,pair<int, int>> const& p1, pair<int,pair<int, int>> const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.first > p2.first;
    }
};
class Solution {
    
    
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int, int>>>,CompareFirstIndex>pq;
        int n = matrix.size();
        
        //put first element of each row into pq; 
        for(int i = 0 ; i <n;i++)
        {
            pq.push(make_pair(matrix[i][0],make_pair(i,0)));
        }
        int x = k , ans;
        
        //checking every index from 0 to k
        //from the first element to the n-1 element.
        while(x--)
        {
        
            int e = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            ans = e;
            pq.pop();
            cout<<x<<" "<<e<<endl;
            if(j != n-1)
                pq.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
        }
        return ans;
//         int n= matrix.size();
//         int row = 0;
//         while(row*n < k)
//         {
//             // k%=n;
//             row++;
//         }
//         row--;
//         k = k - row*n-1;
//         if(row>=n)
//             return -1;
        
        
//         return matrix[row][k];
    }
};