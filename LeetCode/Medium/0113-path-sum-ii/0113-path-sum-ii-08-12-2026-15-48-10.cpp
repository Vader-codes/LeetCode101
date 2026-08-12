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
    vector<vector<int>>ans;
    private:
    void dfs(TreeNode* root, int target, int sum, vector<int>path){
            if(!root)return;
        // first add the currecnt to the ansewr
        if(!root->left && !root->right){
            if(sum == target)ans.push_back(path);
        }
        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left, target, sum+root->left->val, path);
            path.pop_back();
        }
          if(root->right){
            path.push_back(root->right->val);
            dfs(root->right, target, sum+root->right->val, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return ans;

        vector<int>temp;
        temp.push_back(root->val);
        dfs(root, targetSum, root->val, temp);
        return ans;
    }
};