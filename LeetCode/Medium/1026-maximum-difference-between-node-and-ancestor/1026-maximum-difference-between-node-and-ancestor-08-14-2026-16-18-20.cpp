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
    int maxDiff = 0;
    void dfs(TreeNode* root, vector<int>&arr){
        if(!root)return;

        arr.push_back(root->val);

        int curr = root->val;
        for(int x: arr){
            maxDiff = max(maxDiff, abs(curr-x));
        }
        dfs(root->left, arr);
        dfs(root->right, arr);
        arr.pop_back();

    
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        // just do a simple dfs but remember the path
        vector<int>path;
        dfs(root, path);
         return maxDiff;           
    }
};