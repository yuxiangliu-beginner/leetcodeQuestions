/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeHelper(data);
    }
private:
     TreeNode* deserializeHelper(string  & data)
     {
         if(data[0]=='#'){
            if(data.size() >1)
                data = data.substr(2);
             return nullptr;
         }
         else{
             TreeNode* node = new TreeNode(helper(data));
             node->left = deserializeHelper(data);
             node->right =deserializeHelper(data);
             return node;
         }
 
            
     }
    int helper(string & str)
    {
        int pos = str.find(',');
        int val = stoi(str.substr(0,pos));
        str = str.substr(pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));