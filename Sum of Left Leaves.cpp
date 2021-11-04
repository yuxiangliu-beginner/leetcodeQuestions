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
    int helper(TreeNode* root,bool isLeft)
    {
        if(root==nullptr)
            return 0;
        if(isLeft == true && root->left == nullptr && root->right == nullptr)
            return root->val;
        
        return helper(root->left,true)+ helper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
            return helper(root,false);
        //         if(root==nullptr)
//             return 0;
        
//         if(root->left->left == nullptr && root->left->right == nullptr)
//             return root->left->val;
        
        
//         cout<<root->val <<endl;
//         return sumOfLeftLeaves(root->left)+ sumOfLeftLeaves(root->right);
    }
};