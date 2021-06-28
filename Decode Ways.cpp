// https://leetcode.com/problems/decode-ways/discuss/740182/C%2B%2B-Recursion-or-Recursion-with-memoization-or-DP-Explained

class Solution {
public:
    int numDecodings(string s) {
        // vector<int> dp[s.size()];
        //dp[0] = s[0]
        //dp[1] = s[0] + dp[1]  + dp
//         "1226"
        // 0 1 
        // 12: 0 1 2
        //122: 0 1 2 (2+1)
        //1226: 0 1 2 3 (2+3)
        // A B B F
        // A 22 6
        // A B 26
        // 12 2 26
        // 12 26
   
        
        vector<int> dp(s.size()+1);
        dp[0] = 1; 
        if(s[0]=='0')
        {
             dp[1] = 0;
        }
        else{
             dp[1]= 1;
        }
        for(int i=2;i<=s.size();i++)            
        {
            int way1, way2;
            //way1
            if(s[i-1]=='0')
                way1=0;
            else
                way1 = dp[i-1];
            
            if(stoi(s.substr(i-2,2))<=26 && stoi(s.substr(i-2,2))>0 && s[i-2]!='0')
                way2 = dp[i-2];
            else
                way2 = 0;
            
            cout<<way1<<" "<<way2<<endl;
            dp[i] = way1+way2;
        }

        return dp[s.size()];
    }
};