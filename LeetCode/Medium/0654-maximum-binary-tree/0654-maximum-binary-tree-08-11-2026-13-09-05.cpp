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
     unordered_map<int,int>numIdx;
    int max_ele(vector<int>&nums, int left, int right){
        int idx = -1;
        int maxi = INT_MIN;
        for(int i=left; i<= right; i++){
            if(nums[i] > maxi ){
                maxi = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    TreeNode* helper(vector<int>&nums, int left, int right){
        // base case for our recursion
        if(left > right) return NULL;

        //  we need to find the max element in the given range
        int idx = max_ele(nums, left, right);
        int val = nums[idx];
       

        // crate a node
        TreeNode* root = new TreeNode(val);
        // now for its left and right do the same recursively
        root->left = helper(nums,left, idx-1 );
        root->right = helper(nums, idx+1, right);
        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       
        for(int i=0; i<nums.size(); i++){
            numIdx[nums[i]] =i;
        }

        return helper(nums, 0, nums.size()-1);

    }
};