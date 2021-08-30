class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> absum;
        for(auto a:A)
        {
            for(auto b : B)
            {
                absum[a+b]++;
            }
        }
        int count = 0;
        for(auto c:C)
        {
            for(auto d:D)
            {
                auto it = absum.find(0-c-d);
                {
                    if(it!=absum.end())
                    {
                        count+= it->second;          
                    }
                }
            }
        }
        return count;
    }
};