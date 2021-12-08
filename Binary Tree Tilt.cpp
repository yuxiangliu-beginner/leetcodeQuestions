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
    int postOrder(TreeNode*root, int &res)
    {
        if(root == nullptr)
            return 0;
        
        int leftSum = postOrder(root->left, res);
        int rightSum = postOrder(root->right, res);
        
        res += (abs(leftSum-rightSum));
        return root->val + leftSum + rightSum;
    }
    int findTilt(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int res = 0 ;
        // cout<<root->val<<endl;
        postOrder(root,res);
        return res;
    }
};