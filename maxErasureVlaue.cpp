class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> seen;
        int l =0, ans = 0, sum = 0;
        
        for(int r = 0;r < nums.size();r++)
        {
            int currentValue = nums[r];
            //find same element
            if(seen.find(currentValue)!=seen.end())
            {
                int index = seen[currentValue];
                while(l<=index)
                {
                    seen.erase(nums[l]);
                    sum-=nums[l];
                    l+=1;
                }
            }
            //not find
            seen[currentValue] = r;
            sum+=currentValue;
            ans = max(sum,ans);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         unordered_map<int,int> seen;
        
//         int l = 0;
//         int sum = 0;
//         int ans = 0;
        
//         for(int r = 0; r< nums.size();r++)
//         {
//             int x = nums[r];
//             if(seen.find(x)!=seen.end())
//             {
//                 //see this element before;
//                 int index = seen[x];
//                 while(l <= index)
//                 {
//                     seen.erase(nums[l]);
//                     sum-=nums[l];
//                     l+=1;
//                 }
//             }
//             seen[x] = r;
//             sum+=x;
//             ans =  max(ans,sum);
//         }
//         return ans;
    }
};