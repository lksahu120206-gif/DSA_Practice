/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
public:
    bool isSumProperty(Node* root) {
        if (root == nullptr) return true;

        // Leaf nodes are always valid
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        int leftValue = 0;
        int rightValue = 0;

        if (root->left != nullptr) {
            leftValue = root->left->data;
        }

        if (root->right != nullptr) {
            rightValue = root->right->data;
        }

        return root->data == leftValue + rightValue &&
               isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};