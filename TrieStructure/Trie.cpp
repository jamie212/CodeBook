#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
    public:
        struct TrieNode {
            TrieNode* children[26];
            bool isEnd;
    
            TrieNode() : isEnd(false) {
                for(int i = 0; i < 26; ++i) {
                    children[i] = nullptr;
                }
            }
        };
    
        TrieNode* root;
    
        Trie() {
            root = new TrieNode();
        }
    
        // insert word
        void insert(const string& word) {
            TrieNode* node = root;
            for(char c : word) {
                int idx = c - 'a';
                if(!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    
        // check if word exists
        bool search(const string& word) {
            TrieNode* node = root;
            for(char c : word) {
                int idx = c - 'a';
                if(!node->children[idx]) return false;
                node = node->children[idx];
            }
            return node->isEnd;
        }
    
        // check if any word starts with the given prefix
        bool startsWith(const string& prefix) {
            TrieNode* node = root;
            for(char c : prefix) {
                int idx = c - 'a';
                if(!node->children[idx]) return false;
                node = node->children[idx];
            }
            return true;
        }
    };

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true
    return 0;
}
    