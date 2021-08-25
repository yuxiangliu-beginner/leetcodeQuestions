class Solution {
public:
    bool judgeSquareSum(int c) {
        int top = sqrt(c);
        int bot = 0, det = 0;
        while(bot<= top)
        {
            det = top*top + bot*bot;
            if(det==c)
                return true;
            else if(det < c)
            {
                bot++;
            }else
            {
                top--;
            }

        }
        return false;
    }
};