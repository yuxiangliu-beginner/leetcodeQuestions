
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;

        vector<int> dp(n,1);
        int count = 1;
        for(int i = 1 ; i < nums.size(); ++i)
        {
            for(int j =0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            count = max(count, dp[i]);
        }
        return count;
        // length[0] = 1;
        // int min = -1;
//         priority_queue<int,vector<int>,greater<int>> pq;
//         pq.push(nums[0]);
//         int count = 0;
//         for(int i = 1; i < nums.size() ; i++)
//         {
//             if(num[i] < nums[i])
//             {
//                 cout<<pq.top()<<" "<<nums[i]<<' ';
//                 pq.pop();
//                 count++;
//                 pq.push(nums[i]);
//             }
//         }
        
        
//         return count;
    }
};