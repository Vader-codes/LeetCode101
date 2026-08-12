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
    vector<vector<int>>allPaths;
    void dfs(TreeNode* root, vector<int>path){

        if(!root->left && !root->right)allPaths.push_back(path);

        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left,path );
            path.pop_back();
        }
        
        if(root->right){
            path.push_back(root->right->val);
            dfs(root->right,path );
            path.pop_back();
        }
    }
public:
    int sumNumbers(TreeNode* root) {
     if(!root)return 0;
    // step 1 lets collect all the path from root to leaf nodes

     vector<int>temp;
     temp.push_back(root->val);
     dfs(root, temp);
     // now lets make the answer
     int answer =0;
     for(auto arr : allPaths){
        int sum = 0;
         for(auto x : arr){
             sum = sum*10 + x;
         }
         answer+=sum;
     }
return answer;

    }
};