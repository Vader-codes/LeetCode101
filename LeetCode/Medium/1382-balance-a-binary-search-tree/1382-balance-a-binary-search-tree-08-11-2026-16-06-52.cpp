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
    private:
    void dfs(TreeNode* root, vector<int>&arr){
        if(!root)return;

        dfs(root->left, arr);
        // collect the element
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
    TreeNode* helper(vector<int>&inorder, int left, int right){
        if(left > right)return NULL;

        int mid = (left+right)/2;

        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = helper(inorder, left, mid-1);
        root->right = helper(inorder, mid+1, right);

        return root;

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        dfs(root, inorder);

        return helper(inorder, 0, inorder.size()-1);
    }
};