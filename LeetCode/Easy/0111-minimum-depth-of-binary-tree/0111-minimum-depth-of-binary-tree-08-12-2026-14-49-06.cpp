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
    int mini = INT_MAX;
    private:
    int helper(TreeNode* root){
        if(!root)return 0;

       if(!root->left){
        return 1+helper(root->right);
       }
       if(!root->right){
        return 1+helper(root->left);
       }

        return  1+min(helper(root->left), helper(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;

        return helper(root);
    }
};