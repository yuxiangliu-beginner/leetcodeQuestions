// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567291/C%2B%2B-Simple-and-Clean-Solution-Easy-Explanation
class Solution {
public:
    int maskWork(string word)
    {
        int mask = 0 ;
        for(auto c:word)
                mask |= (1 << (c-'a'));
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> mask_freq;
        for(auto word: words)
        {
            mask_freq[maskWork(word)]++;
        }
        
        
        vector<int> res;
        
        for(auto p : puzzles)
        {
            int mask = maskWork(p);
            int submask = mask;
            int first = (1<<(p[0]-'a'));
            int curr = 0;
            while(submask)
            {
                if(submask & first )
                    curr+=mask_freq[submask];
                
                submask = (submask-1) & mask;
            }
            res.push_back(curr);
        }
        return res;
    }
};