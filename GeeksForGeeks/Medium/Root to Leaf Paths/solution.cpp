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
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& ans) {
        if (node == nullptr) return;

        path.push_back(node->data);

        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(path);
        } 
        else {
            dfs(node->left, path, ans);
            dfs(node->right, path, ans);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, path, ans);

        return ans;
    }
};