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
    map<int, int>inorderIdx;
    int preIdx =0;
    private:
    TreeNode* helper(vector<int>& preorder, int left, int right){
        if(left > right)return NULL;

        int val = preorder[preIdx++];

        TreeNode* root = new TreeNode(val);
        int mid = inorderIdx[val];
        root->left = helper(preorder, left, mid-1);
        root->right = helper(preorder, mid+1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderIdx[inorder[i]] =i;
        }

        return helper(preorder, 0, inorder.size()-1);
    }
};