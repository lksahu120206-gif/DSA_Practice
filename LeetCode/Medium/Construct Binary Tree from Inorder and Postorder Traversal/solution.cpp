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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inPos;

        for (int i = 0; i < inorder.size(); i++) {
            inPos[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1, postIndex, inPos);
    }

private:
    TreeNode* build(vector<int>& postorder, int inStart, int inEnd,
                    int& postIndex, unordered_map<int, int>& inPos) {

        if (inStart > inEnd) {
            return nullptr;
        }

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inPos[rootValue];

        // Build right first because postorder is read backwards:
        // root -> right -> left
        root->right = build(postorder, rootIndex + 1, inEnd, postIndex, inPos);
        root->left = build(postorder, inStart, rootIndex - 1, postIndex, inPos);

        return root;
    }
};