class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        vector<string> strsCopy(strs.begin(),strs.end());
        
        int i = 0;
        for(auto a: strs)
        {
            sort(a.begin(),a.end());
            mp[a].push_back(strsCopy[i]);
            i++;
        }
        
        for(auto m : mp)
        {
            res.push_back(m.second);
        }
        return res;
    }
};