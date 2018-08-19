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
* Bug 1: The tree doesn't restore its previous form!
* Bug 2: No uniqueness insurance
*/
class Solution {
private:
    void buildTrees(vector<TreeNode*>& container,
                    int value,
                    TreeNode* tree,
                    unordered_set<int>& existedValues,
                    int size) {
        printf("!debug: on value: %d\n", value);
        existedValues.insert(value);
        
        if (tree == nullptr) {
            tree = new TreeNode(value);
        } else {
            TreeNode* root = tree;
            while (true) {
                if (root->val < value) {
                    if (root->right == nullptr) {
                        root->right = new TreeNode(value);
                        break;
                    } else {
                        root = root->right;
                    }
                } else {
                    if (root->left == nullptr) {
                        root->left = new TreeNode(value);
                        break;
                    } else {
                        root = root->left;
                    }
                }
            }   
        }
        
        for (int i = 1; i <= size; ++i) {
            if (existedValues.find(i) == existedValues.end()) {
                buildTrees(container, i, tree, existedValues, size);
            }
        }
        
        if (existedValues.size() == size) {
            container.push_back(tree);
            printf("!debug: treee built!\n");
        }
        printf("!debug:poping value: %d\n", value);
        existedValues.erase(value);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        unordered_set<int> existedValues;
        for (int i = 1; i <= n; ++i) {
            TreeNode* root = nullptr;
            buildTrees(result, i, root, existedValues, n);
            printf("!debug:finished one root\n");
        }
        
        return result;
    }
};
