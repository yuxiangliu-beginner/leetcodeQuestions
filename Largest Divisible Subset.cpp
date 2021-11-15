class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1);
        vector<int> previous(n,-1);
        
        int max_index = 0;
        
        for(int i = 1; i < n;i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    previous[i] = j;
                    
                }
            }
            if(dp[i] > dp[max_index])
            {
                max_index = i ;
            }
        }
        
        int t = max_index;
        vector<int>  res;
        while(t>=0)
        {
            res.push_back(nums[t]);
            t = previous[t];
        }
        return res;
        
        
    }
};