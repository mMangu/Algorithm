#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map<string, Node> child;
};


void insert(Node &node, vector<string> &arr, int idx = 0) {
    if (idx == arr.size()) return;
    if (!node.child.count(arr[idx])) node.child[arr[idx]] = Node();
    insert(node.child[arr[idx]], arr, idx + 1); 
}

void find(Node &node, int depth = 0) {
    for (auto nxt : node.child) {
        for (int i = 0; i < depth; i++) printf("--");
        cout << nxt.first << "\n";
        find(nxt.second, depth + 1);
    }
}

int main() {
    int N; scanf("%d", &N);
    Node root;
    while (N--) {
        int K; scanf("%d", &K);
        vector<string> v;
        while (K--) {
            string tmp; cin >> tmp;
            v.push_back(tmp);
        }
        insert(root, v);
    }
    find(root);
}