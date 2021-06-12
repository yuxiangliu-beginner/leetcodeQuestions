// Minimum number of Refueling stop
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        //loop
//         if(startFuel >= target)
//             return 0;
//         //since the loop isort by  the position 
//         //[10,60],[20,30],[30,30],[60,40]
        
        
//         int lastPost= 0;
//         int currentFuel = startFuel;
//         // stations.push_back({target,0});
//         int s = 0 ;
//         for(auto i: stations)
//         {
            
//             if(lastPost+currentFuel<i[0])
//                 return -1;
                    
//             int distance = i[0] - lastPost ;
//             if(currentFuel-distance < i[1] )
//             {
//                 currentFuel = currentFuel-distance + i[1];
//                 lastPost = i[0];
//                 s++;
//             }
//         }
//         cout<<lastPost+currentFuel;
//         if(lastPost+currentFuel>=target)
//             return s;
        
        
        
//         return -1;
        
        //heap
        priority_queue<int> pq;
        stations.push_back({target,0});
        int max_reach = startFuel, ans =0;
        for(auto & i : stations)
        {
            while(!pq.empty() and max_reach < i[0])
            {
                ans++;
                max_reach+=pq.top();
                pq.pop();
            }
            if(max_reach < i[0])
                return -1;
            pq.push(i[1]);
        }
        
        return ans;
    }
};
// longest substring without repeating characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //using slidign windows, keep loop the string,
        //for every char if it contains repeat character, it pop until it does not have , add new char to the back.
        
        
        string res ="";
        int maxLength = 0;
        for(char c:s)
        {
            cout<<res<<endl;
       
            if(res.find(c)!=std::string::npos)
            {
                res=res.substr(res.find(c)+1);
            }
            res+=c;
            int resLen = res.length();
            maxLength = std::max(maxLength,resLen);
        }
        
        
        return maxLength;
    }
};
// 2/10
// set Matrix to Zeros
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int r = 0, c = 0;
        for(int i = 0 ; i < m ; i++)
            if(matrix[i][0] == 0)
                c = 1;
        for(int i = 0 ; i < n ; i++)
            if(matrix[0][i] == 0)
                r = 1;
        
        for(int i = 1; i < m;i++)
        {
            for(int j = 1; j<n;j++)
            {
                 if(matrix[i][j]==0)
                 {
                     matrix[i][0] = 0;
                     matrix[0][j] = 0;
                 }
                
            }
        }
        for(int i = 1; i < m;i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(c==1)
            for( int i = 0 ;i < m ; i++)
                matrix[i][0] = 0;
        
        if(r == 1)
            for(int j = 0 ; j < n; j ++)
                matrix[0][j] = 0;
    }
};
// 3/10
// Add two numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * head = new ListNode(-1);
    ListNode * l = head;
    int c = 0;
    while(l1 || l2)
    {
        int s = c;    
        if(l1)
        {
           s += l1->val;
           l1 = l1->next;
        }
        if(l2)
        {
           s += l2->val;
           l2 = l2->next;
        }
        l->next = new ListNode(s %10);
        l = l->next;
        c = s / 10;
    }
    if(c)
    {
        l->next = new ListNode(c);
    }
        return head->next;
    }
};
// 4/10
// Odd even likenedlist
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        if(!head->next)
            return head;
        
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * even2 = even;
        
        int flag= 0;
        
        while(odd->next && even->next)
        {
            flag = 0;
            odd->next = even->next;
            if(even->next->next){
                flag = 1;
                even->next = even->next->next;
            }
            odd = odd->next;
            if(flag == 1)
                even = even->next;
        }
        odd->next = even2;
        even->next = nullptr;
        return head;
    }
};
// 5/10
// Group anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        vector<string> str(strs.begin(),strs.end());
        
        int i = 0 ;
        
        for(auto a:strs)
        {
            cout<<a<<" ";
            sort(a.begin(),a.end());
            cout<<a<<" "<<str[i]<<endl;
            mp[a].push_back(str[i]);
            i++;
        }
        for(auto a: mp)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};
// 6/10
// Generate parenthesess
class Solution {
public:
    
    void generate(int n, vector<string>& res, int currOpen, string curr)
     {
         if(currOpen<0)
             return;
        if(n==0)
        {
            while(currOpen!=0)
            {
                currOpen--;
                curr+=")";
            }
            res.push_back(curr);
            return;
        }
        generate(n-1,res,currOpen+1,curr+"(");
        generate(n,res,currOpen-1,curr+")");
        
         
     }
    vector<string> generateParenthesis(int n) {
        string s ="";
        vector<string> ans;
        int currOpen = 1;
        
        generate(n-1,ans,currOpen,"(");
        return ans;
    }
};
// 7/10
// permutation
class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>nums,vector<int> a,set<int> s)
    {
        if(a.size() == nums.size())
            ans.push_back(a);
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(s.find(nums[i])==s.end())
            {
                a.push_back(nums[i]);
                s.insert(nums[i]);
                helper(ans,nums,a,s);
                s.erase(s.find(nums[i]));
                a.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> a;
        set<int> s;
        
        helper(ans,nums,a,s);
        return ans;
    }
};
// 8/10
// Jump game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for(int i = 0 ; i < n;i++)
        {
            if(reach <i)
                return false;
            reach = max(reach, i+nums[i]);
        }
        
        return true;
    }
};
// 9/10
// Unique path
class Solution {
public:
    int uniquePaths(int m, int n) {
    
        vector<vector<int>> dp(m,vector<int>(n,0));
        
       for(int i = 0 ; i < m ; i++)
           dp[i][0] = 1;
       for(int j = 0 ; j < n ; j++)
            dp[0][j]=1;
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j  < n ; j++)
            {
    
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// 10/10

