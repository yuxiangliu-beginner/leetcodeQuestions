// https://leetcode.com/problems/perfect-squares/discuss/71512/Static-DP-C%2B%2B-12-ms-Python-172-ms-Ruby-384-ms
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};
        while(dp.size()<=n)
        {
            int m = dp.size(), squares =INT_MAX;
            for(int i = 1; i*i <=m ;++i)
            {
                squares = min(squares,dp[m-i*i]+1);
            }
            dp.push_back(squares);
        }
        return dp[n];
    }
};