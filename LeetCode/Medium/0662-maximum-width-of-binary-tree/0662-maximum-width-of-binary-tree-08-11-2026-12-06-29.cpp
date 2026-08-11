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
    int widthOfBinaryTree(TreeNode* root) {
        typedef unsigned long long ll;
        queue<pair<ll, TreeNode*>>q;
        q.push({0, root});

        ll maxWidth = 0;
        while(!q.empty()){
            int size = q.size();

            ll l = q.front().first;
            ll r = q.back().first;

            maxWidth = max(maxWidth, r-l+1);

            // now process alll the nodes on this level
            while(size--){
                TreeNode* node = q.front().second;   
                ll idx = q.front().first;
                q.pop();

                if(node->left)q.push({2*idx+1,node->left});
                if(node->right)q.push({2*idx+2, node->right});
            }
        }
        return maxWidth;
    }
};