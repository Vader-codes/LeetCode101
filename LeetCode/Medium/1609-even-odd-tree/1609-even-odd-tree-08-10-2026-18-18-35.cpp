/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    private:
    bool check_level(vector<int>&arr, int level){
        int n = arr.size();
        if(level %2 == 0){
               // for even level odd + increasing
               for(int i=0; i<n; i++){
                if(arr[i] %2 == 0)return false;

                if( i < n-1 && arr[i] >= arr[i+1])return false;
               }
        }
        else{
             // for odd level even + decreasing
              for(int i=0; i<n; i++){
                if(arr[i] %2 == 1)return false;

                if( i < n-1 && arr[i] <= arr[i+1])return false;
               }
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return false;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();

            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
            
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (!check_level(temp, level))
                return false;

            level++;
        }

        return true;
    }
};