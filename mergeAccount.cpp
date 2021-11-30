class Solution {
private:
    map<string,string> parent;
    map<string,string> emailToName;
    
public:
    string find(string A)
    {
        while(parent[A]!=A)
            A = parent[A];
        return A;
    }
    void unionSet(string A , string B)
    {
        string rootA = find(A);
        string rootB = find(B);
        parent[rootB] = rootA;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> res;
        
        //set up graph
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size();j++)
            {
                parent[accounts[i][j]] = accounts[i][j];
                emailToName[accounts[i][j]]= accounts[i][0];
            }
        }
        //Using union operation
        for(int i = 0 ; i < n;i++)
        {
            string firstEmail = accounts[i][1];
            for(int j = 2; j < accounts[i].size();j++)
            {
                unionSet(firstEmail, accounts[i][j]);
            }
        }
        //find root and set root email addrss
        map<string,set<string>> mergedAccount;
        for(int i =0 ; i < n; i ++)
        {
            for(int j = 1; j < accounts[i].size();j++)
            {
                string curEmail = accounts[i][j];
                string rootOfEmail = find(curEmail);
                mergedAccount[rootOfEmail].insert(curEmail);
            }
        }
        
        
        map<string,set<string>>::iterator it;
        for(it = mergedAccount.begin(); it != mergedAccount.end(); it++)
        {
            string name = emailToName[it->first];
            set<string> emails = it->second;
            vector<string> temp;
            temp.push_back(name);
            for(string s : emails)
                    temp.push_back(s);
            res.push_back(temp);
        }
        
        return res;
    }
};