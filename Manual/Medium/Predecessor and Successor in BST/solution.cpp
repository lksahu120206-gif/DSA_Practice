pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1, succ = -1;

    TreeNode* curr = root;

    // Find predecessor
    while (curr) {
        if (curr->data < key) {
            pred = curr->data;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    curr = root;

    // Find successor
    while (curr) {
        if (curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return {pred, succ};
}