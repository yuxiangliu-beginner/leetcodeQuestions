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
//     int postId;
//     map<int,int> map;
//     TreeNode* dfs(int left, int right, vector<int>& postorder )
//     {
        
//         if(left > right){
//             return nullptr;
//         }
//         int val = postorder[postId--];
//         TreeNode * root = new TreeNode(val);
//         int mid = map[root->val];
//         root->right = dfs(mid+1, right,postorder);
//         root->left = dfs(left, mid-1,postorder);
//       // root->right = dfs(mid+1, right,postorder);
//         return root;
//     }
    
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = postorder.size();
//         postId = postorder.size()-1;
        
//         for(int i = 0 ;i < n ;i++)
//             map[inorder[i]]= i;
       
//         return dfs(0,n-1,postorder);
//     }
    TreeNode *buildHelper(vector<int>& inorder,vector<int>& postorder,int inorderBegin, int inorderEnd,int& postIndex)
    {
        if(inorderBegin>inorderEnd)
            return nullptr;
        int midValue = postorder[postIndex--];
        int midIndex = find(inorder.begin(),inorder.end(),midValue)-inorder.begin();
        TreeNode * root = new TreeNode(midValue);
        // cout<<midValue<<endl;
        root->right = buildHelper(inorder,postorder,midIndex+1,inorderEnd,postIndex);
        // cout<<midValue<<" "<<inorderBegin<<" "<<midIndex-1<<endl;
        root->left = buildHelper(inorder,postorder,inorderBegin,midIndex-1,postIndex);
        
        cout<<midValue<<endl;
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int postId =postorder.size()-1;
        return buildHelper(inorder,postorder,0,inorder.size()-1,postId);
    }
//     unordered_map<int,int> mp;
//     TreeNode *buildHelper(vector<int> & inorder, int inorderStart, int inorderEnd,vector<int> & postorder, int postorderStart, int postorderEnd)
//     {
//         if(inorderStart > inorderEnd || postorderStart > postorderEnd)
//             return nullptr;
        
//         int midValue = postorder[postorderEnd];
//         int midIndex = mp[midValue];
//         cout<<midValue<<endl;
//         TreeNode * root =  new TreeNode(midValue);
//         root->right = buildHelper(inorder,midIndex+1,inorderEnd,postorder,postorderEnd+midIndex-inorderEnd ,postorderEnd-1);
//         root->left = buildHelper(inorder,inorderStart,midIndex-1,postorder,postorderStart, postorderEnd+midIndex-inorderEnd-1);

      
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//     {
//         int n = inorder.size();
//         for(int i = 0 ; i < inorder.size();i++)
//         {
//             mp[inorder[i]] = i;
//         }
//         return buildHelper(inorder,0,n-1,postorder,0,n-1);
            
//     }
};