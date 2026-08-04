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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int limit) {
        if (preIdx >= pre.size()) {
            return NULL;
        }
        if (in[inIdx] == limit) {
            inIdx++;
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preIdx++]);
        root->left = dfs(pre, in, root->val);
        root->right = dfs(pre, in, limit);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
