// https://leetcode.com/problems/k-inverse-pairs-array/discuss/1283025/C%2B%2B-or-Explained-or-How-to-Build-Up-The-Idea
class Solution {
public:
	// TIME COMPLEXITY:- O(n*k)
	// SPACE COMPLEXITY:- O(n*k)
	// we can reduce the space complexity easily to O(k)
    int kInversePairs(int n, int k) {
        int MOD = 1000000007;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int N = 1; N<=n; N++){
            for(int K=1;K<=k;K++){
                dp[N][K] = (dp[N-1][K]+dp[N][K-1])%MOD;
                if(K-N>=0){
                    dp[N][K] = (dp[N][K] - dp[N-1][K-N]+MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};