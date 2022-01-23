class Solution {
public:
    int dp[100001];
    bool winnerSquareGame(int n) {
        
        for(int i = 1; i <=n; i++)
        {
            dp[i] = -1;
        }
        return solve(n);
    }
    bool solve(int n)
    {
        if(n == 1)return true;
        if(dp[n]!=-1)
            return dp[n];
        
        
        for(int i =1; i*i<=n;i++)
        {
            if(solve(n-i*i)==false)
            {
                dp[n] = 1;
                return true;
            }   
            
        }
        dp[n]=0;
        return false;
    }
};