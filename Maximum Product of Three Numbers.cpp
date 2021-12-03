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
    // int maximumProduct(vector<int>& nums) 
    // {
    //     sort(nums.rbegin(),nums.rend());
    //     int n = nums.size()-1;
    //     return max((nums[0]*nums[1]*nums[2]),(nums[n]*nums[n-1]*nums[0]));
    // }
     int maximumProduct(vector<int>& nums) 
     {
         int max1=INT_MIN;
         int max2=INT_MIN;
         int max3=INT_MIN;
         int min1=INT_MAX;
         int min2=INT_MAX;
         
         for(auto n : nums)
         {
             if(n>max1)
             {
                 max3 = max2;
                 max2 = max1;
                 max1 = n;
             }else if(n> max2)
             {
                 max3 = max2;
                 max2 = n;
             }else if(n >max3)
             {
                 max3 = n;
             }
             
             if(n<min1)
             {
                 min2 =min1;
                 min1 =n;
             }else if(n < min2)
             {
                 min2 = n;
             }
         }
         return std::max(max1*max2*max3,min1*min2*max1);
         
     }
};