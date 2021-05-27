class Solution {
public:
    int maxProduct(vector<string>& words) {
       // We define the bitmask of a word as: If this word contains character a then we turn on bit 0th, b then turn on bit 1th..., z then turn on bit 25th.
        //Now words[i] and words[j] have no common letters if and only if words[i] & words[j] == 0.
        vector<int> mask(words.size());
        int result = 0;
        
        for(int i  = 0; i < words.size() ; i++)
        {
            for (char c:words[i])
            {
                mask[i] |= 1<<(c-'a');
            }
            for(int j = 0; j <i;j++)
            {
                if(!(mask[i] & mask[j]))
                {
                    result = max(result, int(words[i].size() * words[j].size()));
                }
                
            }
        }
        return result;
    }
};