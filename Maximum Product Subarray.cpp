// https://leetcode.com/problems/maximum-product-subarray/discuss/183483/JavaC%2B%2BPython-it-can-be-more-simple
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        if(n== 1)
            return nums[0];
        int l = 0;
        int r = 0;
        int res = INT_MIN;
        
        for(int i = 0 ; i < n;i++)
        {
            l = (l?l:1) * nums[i];
            r = (r?r:1) * nums[n-1-i];
            cout<<l<<" "<<r<<endl;
            res = max(res,max(l,r));
        }
        return res;
    }
};