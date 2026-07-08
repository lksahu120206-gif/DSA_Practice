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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inPos;

        for (int i = 0; i < inorder.size(); i++) {
            inPos[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(preorder, 0, inorder.size() - 1, preIndex, inPos);
    }

private:
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd,
                    int& preIndex, unordered_map<int, int>& inPos) {

        if (inStart > inEnd) {
            return nullptr;
        }

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inPos[rootValue];

        root->left = build(preorder, inStart, rootIndex - 1, preIndex, inPos);
        root->right = build(preorder, rootIndex + 1, inEnd, preIndex, inPos);

        return root;
    }
};