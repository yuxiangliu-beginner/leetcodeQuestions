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
    unordered_map<TreeNode *,int> Flag1;
    unordered_map<TreeNode *,int> Flag0;
    
public:
    int rob(TreeNode* root) {
        return DFS(root, 1);
    }
    int DFS(TreeNode* root, int flag) //flag = 1, can chose , 0 = false
    {
       if(root == nullptr)
            return 0;
       if(flag==1 && Flag1.find(root)!=Flag1.end())
           return Flag1[root];
       if(flag==0 && Flag0.find(root)!=Flag0.end())
           return Flag0[root];
        
        int ret;
       if(flag == 0 )
       {
           ret =  DFS(root->left,1)+DFS(root->right,1);
       }else
       {
           int option1 = root->val + DFS(root->left,0)+DFS(root->right,0);
           int option2 = DFS(root->left,1) + DFS(root->right,1);
           ret = max(option1,option2);
       }
       if(flag == 1)
            Flag1[root] = ret;
       if(flag == 0)
            Flag0[root] = ret;
        
        return ret;
    }
};