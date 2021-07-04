class Solution {
//     https://leetcode.com/problems/count-vowels-permutation/discuss/1315113/C%2B%2BPython-Top-down-DP-Bottom-up-DP-Picture-explain-Clean-and-Concise
public:
    const int a = 0, e = 1, i = 2, o = 3, u = 4, MOD = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<long long>dp(5,1LL),preDP(5,1LL);
        
        while(n-- > 1)
        {
            dp[a] = (preDP[e]+preDP[i]+preDP[u]) %MOD;
            dp[e] = (preDP[a]+preDP[i]) %MOD;
            dp[i] = (preDP[e]+preDP[o]) %MOD;
            dp[o] = preDP[i];
            dp[u] = (preDP[i]+preDP[o]) %MOD;
            dp.swap(preDP);
        }
        return accumulate(preDP.begin(),preDP.end(), 0LL) % MOD;
    }
};