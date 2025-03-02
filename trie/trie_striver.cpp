#include <iostream>
using namespace std;


class Trie {
private:
    struct Node {
        Node* links[26];
        bool flag = false;

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word, bool prefix = false) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return prefix ? true : node->isEnd();
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

class BitTrie {
private:
    struct Node {
        Node* links[2];

        bool containsKey(int bit) {
            return links[bit] != nullptr;
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }

        Node* get(int bit) {
            return links[bit];
        }

    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int max = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                max |= (1 << i);
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return max;
    }
};


int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");

    cout << "Search if Strawberry exists in trie: " <<
        (trie.search("strawberry") ? "True" : "False") << endl;

    cout << "Search if Strike exists in trie: " <<
        (trie.search("strike") ? "True" : "False") << endl;

    cout << "If words in Trie start with Stri: " <<
        (trie.startsWith("stri") ? "True" : "False") << endl;

    return 0;
}
