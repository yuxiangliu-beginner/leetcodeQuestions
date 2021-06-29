class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> window;
        int zeroCount = 0;
        int maxLength = -1 ;
        for(int i = 0 ; i < nums.size(); i++)
        {
            // cout<<nums[i]<<" "<<zeroCount<<endl;
            if(nums[i]==1)
            {
                window.push_back(1);
            }
            if(nums[i]==0)
            {
                zeroCount++;
                window.push_back(0);
            }
            while(window.size()&&zeroCount>k)
            {
                // cout<<"nums.front() "<<window.front()<<endl;
                if(window.front()==0)
                {
                    zeroCount--;
                }
                    
                
                window.pop_front();
                
            }
            // for(auto a:window)
            //     cout<<a<<" ";
            // cout<<endl;
            
            
            maxLength = max(maxLength, int(window.size()));
        }
        return maxLength;
        
        
//         int zeroCount = 0, l = 0, maxLength = 0;
        
//         for(int r = 0 ;r < nums.size();++r)
//         {
//             if(nums[r]==0)
//             {
//                 zeroCount++;
//             }
//             while(zeroCount>k)
//             {
//                 if(nums[l]==0)
//                     --zeroCount;
                
//                 ++l;
//             }
//             maxLength = max(maxLength,r-l+1);
//         }
//         return maxLength;
    }
};