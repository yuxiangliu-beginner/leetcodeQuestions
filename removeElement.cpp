class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0 ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i]==val)
                counter++;
            else
                nums[i-counter] = nums[i];
        }
        return nums.size() - counter;
    }
};