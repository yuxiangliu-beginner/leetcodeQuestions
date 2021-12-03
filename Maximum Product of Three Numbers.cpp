class Solution {
public:
    // int maximumProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = INT_MIN;
    //     for(int i = 0 ; i< n;i++)
    //     {
    //         for(int j = i+1;j <n;j++)
    //         {
    //             for(int k = j+1; k < n ;k++)
    //             {
    //                 if(i!=j&&i!=k)
    //                 {
    //                     int m =nums[i]*nums[j]*nums[k];
    //                     // cout<< m<<endl;
    //                     res = max(res, m);
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size()-1;
        return max((nums[0]*nums[1]*nums[2]),(nums[n]*nums[n-1]*nums[0]));
    }
};