// Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high) /2;
            if(target == nums[mid])
                return mid;
            
            //4, 5, 9, 0, 1  -> 9>1
            if(nums[mid] > nums[high])
            {
                //check target, if target < mid , if target = 5 , 5 9, so range is from 4 to 9
                //else target > mid || taget < low, it is on the other range.
                if(target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else 
                    low = mid+1;
            }else if(nums[mid]< nums[low])
            {
                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid+1;
                }else
                {
                    high = mid-1;
                }
            }else
            {
                if(target<nums[mid])
                    high = mid-1;
                else 
                    low = mid+1;
            }
        }
        return -1;
    }
};
// 1/10
// Maximum Units on a Truck
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> l;
        for(auto b:boxTypes)
        {
            l.push_back({b[1],b[0]});
        }
        // for(auto i:l)
        //     cout<<i.first<<" : "<<i.second<<endl;
        sort(l.rbegin(),l.rend());
            //   for(auto i:l)
            // cout<<i.first<<" : "<<i.second<<endl;
        int ans=  0;
        int size = truckSize;
        int count = 0;
        int index = 0;
        while(count<truckSize && index<l.size())
        {
            cout<<l[index].first<<" "<<l[index].second<<endl;
            ans+=(l[index].first*l[index].second);
            
            count+= l[index].second;
            index++;
        }
        if(count>truckSize)
        {
            ans-= (count-truckSize)*l[index-1].first;
        }
        return ans;
    }
};
// 2/10
// Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        // if(coins.size() == 1)
        //     return (amount/ coins[0]);
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1);
        dp[0]=0;
        for(int i = 1 ; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for(int c:coins)
            {
                if(i-c < 0 )
                    break;
                if(dp[i-c]!=INT_MAX)
                    dp[i] = min(dp[i],1+dp[i-c]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// 3/10;
