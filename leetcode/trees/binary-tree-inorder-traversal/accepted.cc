/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Rumtime  : O(n)
 * Space    : O(1)
 */
class Solution {
private:
    void inOrderHelper(vector<int>& container, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        inOrderHelper(container, root->left);
        container.push_back(root->val);
        inOrderHelper(container, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inOrderHelper(result, root);
        return result;
    }
};
