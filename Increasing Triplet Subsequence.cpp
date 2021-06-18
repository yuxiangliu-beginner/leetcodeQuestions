// Greey solution, if there exist a number less or equal to
// both min1 and min2
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1=INT_MAX, min2=INT_MAX;
        for(int i : nums)
        {
            if(i <= min1)
            {
                min1 = i;
            }else if(i <= min2)
            {
                min2 =i;
            }else
            {
                return true;
            }
        }
        return false;
    }
};