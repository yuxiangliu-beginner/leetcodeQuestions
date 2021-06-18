class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         //You must write an algorithm that runs in O(n) time and without using the division operation. 
//         //with division
//         int product =1;
//         bool containzero= false;
//         int zeroSize=0;
//         for(int n:nums){
//             if(n==0){
//                 containzero= true;
//                 zeroSize++;
//                  continue;
//             }       
//             product*=n;
//         }
          
//         vector<int> ans;
        
//         if(zeroSize>=2)
//         {
//             for(int n:nums)
//                 ans.push_back(0);
//         }
//         else if(containzero)
//         {
//             for(int n:nums){
//                 if(n!=0)
//                     ans.push_back(0);
//                 else
//                     ans.push_back(product);

//             }
//         }
//         else
//         {
//              for(int n:nums)
//                 ans.push_back(product/n);
//         }
//         return ans;

        //Time: O(n), space : O(n);
//         int n = nums.size();
//         vector<int> fromBegin(n);
//         vector<int> fromEnd(n);
//         fromBegin[0] = 1;
//         fromEnd[0] = 1;
//         for(int i = 1 ; i < n;i++)
//         {
//             fromBegin[i] = fromBegin[i-1] * nums[i-1];
//             fromEnd[i] = fromEnd[i-1] * nums[n-i];
//         }
        
//         vector<int> ans(n);
//         for(int i = 0 ; i < n;i++)
//         {
//             ans[i] = fromBegin[i] * fromEnd[n-i-1];
//         }
        // return ans;
        
        
         //Time: O(n), space : O(1);
        int n = nums.size();
        int fromBegin=1;
        int fromEnd=1;
        vector<int> ans(n,1);
        
        
        for(int i = 0 ; i < n; i++)
        {
            ans[i]*=fromBegin;
            fromBegin *= nums[i];
            ans[n-1-i] *= fromEnd;
            fromEnd*=nums[n-1-i];
        }
        return ans;
    }
};