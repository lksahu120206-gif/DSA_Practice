class Node {
public:
    Node* links[26];
    int prefixCount;
    int endCount;

    Node() {
        prefixCount = 0;
        endCount = 0;

        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }
};

class Trie {
    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string &word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->links[idx] == nullptr)
                node->links[idx] = new Node();

            node = node->links[idx];
            node->prefixCount++;
        }

        node->endCount++;
    }

    int countWordsEqualTo(string &word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->links[idx] == nullptr)
                return 0;

            node = node->links[idx];
        }

        return node->endCount;
    }

    int countWordsStartingWith(string &word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->links[idx] == nullptr)
                return 0;

            node = node->links[idx];
        }

        return node->prefixCount;
    }

    void erase(string &word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            node = node->links[idx];
            node->prefixCount--;
        }

        node->endCount--;
    }
};