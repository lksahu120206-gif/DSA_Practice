/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:

      void dfs(Node* root, int level, vector<int>& costs) {

          if (root == nullptr)
              return;

          if (root->left == nullptr && root->right == nullptr) {
              costs.push_back(level);
              return;
          }

          dfs(root->left, level + 1, costs);
          dfs(root->right, level + 1, costs);
      }

      int getCount(Node* root, int k) {

          vector<int> costs;

          dfs(root, 1, costs);

          sort(costs.begin(), costs.end());

          int count = 0;

          for (int cost : costs) {

              if (cost > k)
                  break;

              k -= cost;
              count++;
          }

          return count;
      }
  };