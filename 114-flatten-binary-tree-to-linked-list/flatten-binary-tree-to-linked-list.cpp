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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* rightSubTree = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* rightMostElement = root;
        while(rightMostElement->right != NULL){
            rightMostElement = rightMostElement->right;
        }
        rightMostElement->right = rightSubTree;
        flatten(root->right);
    }
};