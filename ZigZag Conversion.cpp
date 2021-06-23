class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        bool conv = true;
//         vector<vector<string>> ans(numRows,vector<string>);
        vector<string> ans(numRows);
        int row = 0 ;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(conv)
                ans[row].push_back(s[i]);
            else
                ans[numRows-1-row].push_back(s[i]);
            row++;
            if(row>=numRows)
            {
                row = 1;
                conv = !conv;
            }
        }
        string res="";
        for(int i = 0; i < ans.size(); i++)
        {
            for(auto a : ans[i])
                res+=a;
            // cout<<endl;
        }
        return res;
        
    }
};