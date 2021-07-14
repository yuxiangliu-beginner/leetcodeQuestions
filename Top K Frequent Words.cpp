class Solution {
//     https://leetcode.com/problems/top-k-frequent-words/discuss/112651/Simple-C%2B%2B-solutions
public:
    struct Comp{
        bool operator()(const pair<int,string> & lhs, const pair<int,string> & rhs) const
        {
            if(lhs.first!=rhs.first)
                return lhs.first < rhs.first;
            
            return lhs.second > rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(string w:words)
            m[w]+=1;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>, Comp> pq;
        for(auto current:m)
            pq.emplace(current.second,current.first);
        
        
        vector<string> res;
        
        while(k-->0 && !pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};