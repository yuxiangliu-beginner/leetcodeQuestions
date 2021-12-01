class Solution {
public:
    int rob(vector<int>& nums) {
        // int sum1 = 0 , sum2 = 0;
        // for(int i = 0 ; i < nums.size() ;i++){
        //     if(!(i&1))
        //         sum1= max(sum1+nums[i],sum2);
        //     else
        //         sum2 = max(sum2+nums[i],sum1);
        // }
        // return max(sum1,sum2);
        
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i =  2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};