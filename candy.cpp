// @ https://leetcode.com/problems/candy/discuss/42878/C%2B%2B-easy-to-understand-Solution-with-lot-of-comments-(-O(n)-constant-space-one-pass)

public:
    // Candies for a slope of n elements
    int slope(int n)
    {
        return (n*(n+1))/2;
    }

    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1 )
        {
            return ratings.size();
        }
        int tot = 0;        // The final amount of candies
        int up = 0;         // Lenght of the last ascending slope
        int down = 0;       // Lenght of the last descending slope
        int oldsign = 0;    // Previous ratings trend (1 = ascending, -1 == descending, 0 = stable) 

        for (int i = 1; i< ratings.size(); i++)
        {
                        // Current ratings trend, same meaning as oldsign
            int newsign = ratings[i] > ratings[i-1] ? 1 : 
                          ratings[i] < ratings[i-1] ? -1 : 0;
                        // We can calculate the contribution of a slope 
                        // when that slope ends and it's not the peak of a mountain,
                        // that's why we have "newsign == 0" and not "newsign <= 0"
            if ((oldsign > 0 && newsign == 0)  ||
                (oldsign < 0  && newsign >= 0) )
                {
                        // The peak of the mountain should have max(up,down)+1
                        // candies, but the end of the mountain is the beginning of
                        // the next sequence, so we don't the candy at the end of 
                        // the mountain
                    tot += slope(up) + slope(down) + std::max(up, down);
                    up = 0;
                    down = 0;
                }

            if(newsign > 0)
                up++;
            if(newsign < 0)
                down++;
                    // Same rating of the previous child?
                    // Take one candy.If you are better then the next child
                    // the descending slope will take that into account, don't worry
            if(newsign == 0)
                tot++;
                
            oldsign = newsign;
        }
        
                    // Final sequence has to be closed
                    // Why +1? Because we don't have a sequence next!
        tot += ramp(up) + ramp(down) + std::max(up, down) + 1;
        return tot;
    }
};