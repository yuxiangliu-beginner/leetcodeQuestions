class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
        if(matrix.empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = INT_MIN;
        
        for(int l = 0 ; l < cols; ++l)
        {
            vector<int> sums(rows,0);
            for(int r = l ; r <cols;++r)
            {
                for(int i =0 ; i < rows;++i)
                {
                    sums[i] += matrix[i][r];
                }
                
           //Find the max Subarry no more than k
            set<int> accuSet;
            accuSet.insert(0);
            int curSum=0, curMax= INT_MIN;
            for(int sum: sums)
            {
                curSum+= sum;
                set<int>::iterator it = accuSet.lower_bound(curSum-k);
                if(it!=accuSet.end())
                    curMax = max(curMax,curSum - *it);

                accuSet.insert(curSum);
            }
                res = max(res,curMax);
            }
            

        }
        return res;      
    }
};