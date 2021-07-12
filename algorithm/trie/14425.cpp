#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

struct Trie {
    bool finish;
    Trie *child[26];

    Trie() : finish(false) {
        memset(child, 0, sizeof(child));
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (child[i]) delete child[i];
        }
    }

    void insert(const char *key) {
        if (*key == 0) {
            finish = 1;
            return;
        }
        int idx = *key - 'a';
        if (!child[idx]) child[idx] = new Trie();
        child[idx] -> insert(key + 1);
    }

    bool check(const char *key) {
        if (*key == 0) return finish;
        int idx = *key - 'a';
        if (!child[idx]) return false;
        bool ret = child[idx] -> check(key + 1);
        return ret;
    }
};

int main() {
    int N, M; scanf("%d %d", &N, &M);
    Trie *root = new Trie();
    while (N--) {
        char tmp[502]; scanf("%s", tmp);
        root -> insert(tmp);
    }
    int ans = 0;
    while (M--) {
        char tmp[502]; scanf("%s", tmp);
        if (root -> check(tmp)) ans++;
    }
    printf("%d", ans);
}