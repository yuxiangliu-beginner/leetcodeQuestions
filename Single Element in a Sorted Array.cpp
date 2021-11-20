// 540. Single Element in a Sorted Array
class Solution {
    
    // the numbser must be odd 2*n + 1;
    // if mid == mid -1;
    // show that even odd even,even+1;
    // odd at left
    // mid = mid -1;
    //show odd at right;
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        int begin =0 , end =nums.size()-1;
        int mid = 0;
        while (begin < end)
        {
            mid = (end-begin)/2+begin;
            // cout<<mid<<endl;
            if(mid %2==0 && nums[mid] == nums[mid + 1])
            {
                 begin = mid+1;
                
            }else if(mid %2==1 && nums[mid] == nums[mid -1])
            {
                begin = mid+1;
            }else
            {
                end =mid;
            }
            
            
        }
        return nums[begin];
    }
};