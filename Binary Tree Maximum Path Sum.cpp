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

// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation
class Solution {
public:
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        // return helper(root);
        
        max_gain(root);
        return max_sum;
    }
    int max_gain(TreeNode * root)
    {
        if(root == 0)
            return 0;
        int l = max(max_gain(root->left),0);
        int r = max(max_gain(root->right),0);
        int new_price = root->val + l + r;
        max_sum = max(max_sum,new_price);
        return root->val  + max(l,r);
        
    }
//     int helper(TreeNode* root){
//         if(root->left == nullptr && root->right==nullptr)
//             return root->val;
//         if(root->left == nullptr )
//             return max(max(root->val,root->right->val),(root->val)+(root->right->val));
//         if(root->right == nullptr)
//             return max(max(root->val,root->left->val),(root->val)+(root->left->val));
//         int l;
//         int r;
        
//         if(root->left->val>=0)
//             l = root->left->val;
//         else 
//             l = 0;
//         if(root->right->val>=0)
//             r = root->right->val;
//         else 
//             r = 0;
        
//         int path = l + r + root->val;
        
//         int left = helper(root->left);
//         int right = helper(root->right);
        
//         return max(left,max(path,right));
        
//     }
};