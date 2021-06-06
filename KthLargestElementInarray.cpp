class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,less<int>> maxHeap;
        
//         for(auto i :nums)
//         {
//             // cout<<i<<endl;
//             maxHeap.emplace(i);
//         }
//         for(int i = 1 ; i < k;i++){
//             cout<<maxHeap.top()<<endl;
//              maxHeap.pop();
//         }
           
        // sort(nums.rbegin(),nums.rend());
        // for(auto i : nums)
        //     cout<<i<<endl;
        // return nums[k-1];

                
        if (k <= 0) return 0;
if (nums.size() < k) return 0;
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        //push faster than emplace
        for(auto i :nums)
        {
            if(minHeap.size()< k)
            {
                minHeap.push(i);
            }
            else
            {
                // int temp =minHeap.top();
                if(minHeap.top()< i)
                {   
                    // cout<<minHeap.top()<<" "<<i<<endl;
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
        }
        // for(int i = 1 ; i < k;i++){
        //     cout<<maxHeap.top()<<endl;
        //      maxHeap.pop();
        // }
        return minHeap.top();
        
    }
};