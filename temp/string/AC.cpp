#include <queue>
#include <string>
#include <iostream>
using namespace std;

const vector<string> patterns {
    "i",
    "he",
    "his",
    "she",
    "hers",
};
const string matchstr = "ushersheishis";

struct Node {
    const char* match;
    Node* fail, * sons[26];
};

Node* BuildTrie() {
    Node* root = new Node();
    for (const auto& p : patterns) {
        Node* node = root;
        for (const auto& c : p) {
            if (node->sons[c-'a'] == nullptr) {
                node->sons[c-'a'] = new Node();
            }
            node = node->sons[c-'a'];
        }
        node->match = p.data();
    }
    queue<Node*> q;
    for (int i=0; i<26; i++) {
        if (root->sons[i]) {
            root->sons[i]->fail = root;
            q.push(root->sons[i]);
        } else root->sons[i] = root;
    }
    while (! q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->fail && node->fail->match && !node->match) {
            node->match = node->fail->match;
        }
        for (int i=0; i<26; i++) {
            if (node->sons[i]) {
                node->sons[i]->fail = node->fail->sons[i];
                q.push(node->sons[i]);
            } else node->sons[i] = node->fail->sons[i];
        }
    }
    return root;
}

void QueryTrie(Node* root) {
    Node* node = root;
    for (const auto& c : matchstr) {
        node = node->sons[c-'a'];
        if (node->match) {
            cout << node->match << endl;
        }
    }
}

int main() {
    QueryTrie(BuildTrie());
    return 0;
}