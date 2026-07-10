/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* levelStart = root;

        while (levelStart->left != nullptr) {
            Node* current = levelStart;

            while (current != nullptr) {
                // Connect children of the same parent
                current->left->next = current->right;

                // Connect across two parents
                if (current->next != nullptr) {
                    current->right->next = current->next->left;
                }

                current = current->next;
            }

            levelStart = levelStart->left;
        }

        return root;
    }
};