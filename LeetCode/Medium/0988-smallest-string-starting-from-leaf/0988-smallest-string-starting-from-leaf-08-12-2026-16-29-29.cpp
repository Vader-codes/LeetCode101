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
    string ans ="";
    private:
    void dfs(TreeNode* root, string path){
            if(!root)return;
        if(!root->left && !root->right){
            // we are at a leaf node
            reverse(path.begin(), path.end());
            
            if( ans.empty() || path < ans){
                // this is smaller than before
                ans = path;
            }
                return;
        }
        // now we can go to both left and then right
        if(root->left){
            path.push_back(char('a'+root->left->val));
            dfs(root->left, path);
            path.pop_back();
        }
        if(root->right){
            path.push_back(char('a'+root->right->val));
            dfs(root->right, path);
            path.pop_back();
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root)return " ";
        string path ="";
        path.push_back(char('a'+root->val));
        dfs(root, path);
        return ans;
    }
};