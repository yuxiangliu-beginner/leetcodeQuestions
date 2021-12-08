class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(nums.size()<4)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i =0 ; i < len -3 ;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j = i+1 ; j < len -2 ; j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                else
                {
                    int l = j +1; 
                    int r = len-1;
                    while(l<r)
                    {
                        long long sum = nums[i]+nums[j];
                        sum += nums[l]+nums[r];
                        if(sum == target)
                        {
                            vector<int> cur;
                            cur.push_back(nums[i]);
                            cur.push_back(nums[j]);
                            cur.push_back(nums[l]);
                            cur.push_back(nums[r]);
                            
                            res.push_back(cur);
                            while(l<r && nums[l]== nums[l+1])
                                l++;
                            while(l<r && nums[r]== nums[r-1])
                                r--;
                            l++;
                            r--;
                        }else if(sum < target)
                        {
                            while(l<r && nums[l]== nums[l+1])
                                l++;
                            l++;
                        }else if(sum > target)
                        {
                            
                            while(r>l && nums[r] == nums[r-1])
                                r--;
                            r--;
                                 
                        }
                        
                    }
                }
            
            }
        }
        return res;
    }
};