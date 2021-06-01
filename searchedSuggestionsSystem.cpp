class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        string prefix = "";
        auto i = products.begin(), it = i;
        int k;
        
        sort(products.begin(), products.end());
        
        for (auto ch : searchWord) {
            vector<string> tmp;
            prefix += ch;
            i = lower_bound(i, products.end(), prefix);
            
            for (it = i, k = 0; it != products.end() && k < 3; k++, it++) {
                if ((*it).find(prefix) == -1) break;
                tmp.push_back(*it);
            }
            res.push_back(tmp);
        }
        return res;
    }
};