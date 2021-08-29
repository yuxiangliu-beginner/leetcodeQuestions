// https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation
class Solution {
public:
    int minPatches(vector<int>& nums, int n) { 
        long missed = 1, added = 0 , i =0 ;
        while(missed<=n)
        {
            if(i<nums.size() && nums[i]<=missed)
            {
                missed+=nums[i++];
            }
            else
            {
                missed += missed;
                added++;
            }
        }
        return added;
    }
};