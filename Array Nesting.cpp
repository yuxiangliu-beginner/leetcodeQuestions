class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> s;
        vector <bool> seen(nums.size());
        int mL=0;
        for(int i = 0 ;i < nums.size();i++)
        {
            int l = 0;
            int temp = nums[i];
            // int temp = nums[i];
            // if(seen.count(temp)>0)
            //     continue;
            // seen.insert(temp);
            // s.insert(temp);

            while(!seen[temp])
            {
                seen[temp] = true;
                l++;
                temp = nums[temp];
                // s.insert(temp);
            }
            // s.clear();
            mL = max(l,mL);
        
        }

        return mL;
        
        
        
//         int res =0,n = nums.size();
        
//         vector<bool> seen(n);
        
//         for(int i :nums)
//         {
//             int cnt =0 ;
//             while(!seen[i])
//             {
//                 see[i] = true;
//                 cnt++;
//                 i = A[i];
//             }
//             res = max(res,cnt);
//         }
    }
};