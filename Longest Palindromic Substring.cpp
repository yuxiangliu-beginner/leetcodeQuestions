class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int n = s.size();
        if(n == 1)
            return s;
        
        
        int min_start = 0 , max_len=1;
        
        
        for(int i = 0; i < n ;)
        {
            if(n-i<=max_len/2)
                break;
            
            
            int j = i,k =i;
            while(k < n-1 and s[k+1] == s[k])
                    ++k;
            
            i = k+1;
            
            while(k< n-1 and j>  0 and s[k+1] == s[j-1])
            {
                ++k;
                --j;
            }
            int new_len=k-j+1;
            if(new_len > max_len)
            {
                min_start = j;
                max_len = new_len;
            }
            
            
        }
        return s.substr(min_start, max_len);
        
//         if(s.length()<=1)
//             return s;
//         int n = s.length();
//         bool dp[n][n];
        
//         for(int i =0; i <n;i++)
//             dp[i][i] = true;
        
        
//         int longestPaliStart = 0, longestPaliLength = 1;
        
//         for(int start = n-1; start>=0; start-- )
//         {
//             for(int end = start+1; end <n; end++)
//             {
//                 if(s[start]==s[end])
//                 {
//                     if(end-start ==1  or dp[start+1][end-1])
//                     {
//                         dp[start][end] = true;
//                         if(longestPaliLength < end-start+1)
//                         {
//                             longestPaliStart = start;
//                             longestPaliLength = end - start +1;
//                         }
//                     }
//                 }
                
//             }
//         }
        
//         return s.substr(longestPaliStart,longestPaliStart+longestPaliLength);
        
    }
};