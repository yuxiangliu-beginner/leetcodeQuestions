// Palindrome pairs
class Solution {
public:
    bool checkPalidrome(string w, int start, int end)
    {
        while(start < end)
        {
            if(w[start++] != w[end--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int > wmap;
        vector<vector<int>> ans;
        
        
        //store every word int map with key word[i] ,value i
        for(int i = 0 ; i < words.size();i++)
        {
            wmap[words[i]]=i;
        }
        
        for(int i = 0 ; i < words.size();i++)
        {
            //if there exist "", we need only to check the other string
            // if it is palidrome and it is not "". then we push in to the ans;
            if(words[i] == "")
            {
                for(int j = 0 ; j < words.size();j++)
                {
                    string & w = words[j];
                    if(checkPalidrome(w,0,w.size()-1) && j != i)
                    {
                        ans.push_back(vector<int> {i,j});
                        ans.push_back(vector<int> {j,i});
                    }
                }
//                 not do other checking
                continue;
            }
            
            //if is a full string, find inverse and find index from map
            string bw = words[i];
            reverse(bw.begin(), bw.end());
            if(wmap.find(bw)!=wmap.end())
            {
                int res = wmap[bw];
                if(res!= i)
                    ans.push_back(vector<int> {i,res});
            }
            
            // testing the palidorme part in a word
            // then check it invers is in the map or not.
            // if it is it mean we can find the it palidorem combining 
            // (e.g. "abcddd" will match with "cba" because "abc" matches with "cba" and "ddd" is a palindrome)
            //
            for(int j = 1; j < bw.size();j++)
            {
                if(checkPalidrome(bw,0,j-1))
                {
                    string s = bw.substr(j,bw.size()-j);
                    if(wmap.find(s)!=wmap.end())
                        ans.push_back(vector<int>{i,wmap[s]});
                }
                if(checkPalidrome(bw,j,bw.size()-1))
                {
                    string s = bw.substr(0,j);
                    if(wmap.find(s)!=wmap.end())
                        ans.push_back(vector<int>{wmap[s],i});
                }
            }
            
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool checkPalidrome(string words)
//     {
//         // cout<<words.size()<<endl;
//         int start = 0;
//         int end = words.size()-1;
//         // cout<<words<<endl;
//         while(start < end)
//         {
//             if(words[start] != words[end])
//                 return false;
            
            
//             start++;
//             end--;
//             // cout<<words[start]<<" "<<words[end]<<endl;
//             //  cout<<start<<" "<<end<<endl;
//         }
            
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         //o(n^2)
//         //time exceeding
//         vector<vector<int>> ans;
//         int n = words.size();
//         for(int i = 0 ; i < n;i++)
//         {
//             for(int j = i+1 ; j < n;j++)
//             {
//                 if(i!=j)
//                 {
//                     // cout<<words[j] + words[i]<<endl;
//                     if(checkPalidrome(words[i] + words[j])){
//                         // cout<<i<<" "<<j<<endl;
//                         ans.push_back({i,j});
//                     }
//                     if(checkPalidrome(words[j] + words[i])){
//                          ans.push_back({j,i});
//                     }
//                     // cout<<i<<" "<<j<<endl;
//                 }
//                 // if(!curr.empty())
//                 //     ans.push_back(curr);
//             }
//         }
//         return ans;
//     }
// };
// 1/10
// rob house
class Solution {
public:
    int rob(vector<int>& nums) {
        // int sum1 = 0 , sum2 = 0;
        // for(int i = 0 ; i < nums.size() ;i++){
        //     if(!(i&1))
        //         sum1= max(sum1+nums[i],sum2);
        //     else
        //         sum2 = max(sum2+nums[i],sum1);
        // }
        // return max(sum1,sum2);
        
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        
        vector<int> dp(nums.size());
        dp[0] =nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2 ; i < nums.size();i++)
        {
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};
// 2/10
 // Binary Tree Inorder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorderTraversalHelper(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)
            return;
        inorderTraversalHelper(root->left,res);
        res.push_back(root->val);
        inorderTraversalHelper(root->right,res);
        return;
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
        inorderTraversalHelper(root,res);
        return res;
        
    }
};
// 3/10
// Binary Tree Zigzag level order Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> temp;
        if(root==nullptr)
            return ans;
        
        temp.push(root);
        bool zigzag = true;
        while(!temp.empty())
        {
            int n = temp.size();
            vector<int> currLevel;
            for(int i = 0; i < n ; i++)
            {
                TreeNode* t = temp.front();
                currLevel.push_back(t->val);
                temp.pop();
                if(t->left)
                    temp.push(t->left);
                if(t->right)
                    temp.push(t->right);
                
            }
            if(zigzag)
                ans.push_back(currLevel);
            else{
                reverse(currLevel.begin(),currLevel.end());
                ans.push_back(currLevel);
            }
                
            
            zigzag = !zigzag;
    
        }
        return ans;
        
    }
};
// 4/10
// Populating Next Right Pointers in Each Node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 1,2,4,8,16...
        // proder ->vector
        //loop vector
        if(!root)
            return nullptr;
        
        if(root->left)
        {
            root->left->next = root->right;
            if(root->next)
            {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
// 5/10
// Kth Smallest Element in a BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int number = 0;
    int count = 0;
    void helper(TreeNode* root)
    {
        if(root->left != nullptr)
            helper(root->left);
        count--;
        if(count == 0)
        {
            number = root->val;
            return;
        }
        if(root->right!=nullptr)
            helper(root->right);
  
        
    }
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        helper(root);
        return number;
    }
};
// 6/10
// Number of Islands
class Solution {
public:
    int ans =0 ;
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0 ; i < grid.size();i++)
        {
            for(int j = 0 ;  j < grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
   void helper(int row,int col, vector<vector<char>>& grid)
    {
       if(row<0||row>=grid.size())
           return;
       if(col<0||col>=grid[0].size())
           return;
        if(grid[row][col]=='0')
            return;
        
        grid[row][col] = '0';
        helper(row-1,col,grid);
        helper(row+1,col,grid);
        helper(row,col-1,grid);
        helper(row,col+1,grid);
        
    }
};
// 7/10
// Word Search
class Solution {
public:
    bool helper(int i,int j,vector<vector<char>>& board, string word)
    {
        // cout<<word<<endl; 
        if(word.size()==0)
            return true;
        if(i<0 || i >= board.size())
            return false;
        if(j<0 || j >= board[0].size())
            return false;
     
        bool res =false;
        if(board[i][j]==word[0]){
            board[i][j]='.';
            res= helper(i-1,j,board,word.substr(1)) ||
            helper(i+1,j,board,word.substr(1)) ||
            helper(i,j-1,board,word.substr(1)) ||
            helper(i,j+1,board,word.substr(1));
            
            board[i][j]=word[0];
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0 ; i < board.size(); i++)
        {
            for(int j = 0 ; j < board[i].size(); j++)
            {
                if(board[i][j]==word[0])
                    if(helper(i,j,board,word))
                        return true;
            }
        }
        return false;
    }
};
// 8/10
 // Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        for(auto num: nums)
            mp[num]++;
        
        
        vector<int> ans;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto m:mp)
        {
            pq.push(make_pair(m.second,m.first));
            if(pq.size() > (int)mp.size() - k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
// priority_queue<pair<int,int>> pq;
// sort by the first element of the pair
// 9/10
// Search a 2D Matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int beginRow = 0 , endRow = matrix.size();
//         int beginCol = 0, endCol = matrix[0].size();
        
        
//         while(beginRow < endRow)
//         {
//             int midRow = (endRow-beginRow)/2;
//             cout<<matrix[midRow][0]<<endl;
//             if(target<matrix[midRow][0])
//             {
//                 beginRow = midRow+1;
//             }else
//             {
//                 endRow = midRow;
//             }
//         }
               
//         while(beginCol < endCol)
//         {
//             int midCol = (endCol-beginCol)/2;
//             if(target<matrix[beginRow][midCol])
//             {
//                 beginCol = midCol+1;
//             }else
//             {
//                 endCol = midCol;
//             }
//         }
//         if(matrix[beginRow][beginCol] == target)
//         {
//             return true;
//         }
        
        
//         return false;
        
            int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }
    return false;
    }
};

// 10/10
