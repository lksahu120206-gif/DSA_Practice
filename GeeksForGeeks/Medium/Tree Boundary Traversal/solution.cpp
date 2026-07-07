/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    bool isLeaf(Node* node) {
        return node != nullptr &&
               node->left == nullptr &&
               node->right == nullptr;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* cur = root->left;

        while (cur) {
            if (!isLeaf(cur)) {
                res.push_back(cur->data);
            }

            if (cur->left) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (root == nullptr) return;

        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* cur = root->right;
        vector<int> temp;

        while (cur) {
            if (!isLeaf(cur)) {
                temp.push_back(cur->data);
            }

            if (cur->right) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        for (int i = (int)temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;

        if (root == nullptr) return res;

        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};