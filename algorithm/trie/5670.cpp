#include <cstdio>
#include <cstring>

struct Trie {
    bool finish;
    int child;
    Trie *nxt[26];

    Trie() : finish(false), child(0) {
        memset(nxt, 0, sizeof(nxt));
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (nxt[i]) delete nxt[i];
        }
    }

    void insert(const char *key) {
        if (*key == 0) {
            finish = 1;
            return;
        }
        int idx = *key - 'a';
        if (!nxt[idx]) {
            child++;
            nxt[idx] = new Trie();
        }
        nxt[idx] -> insert(key + 1);
    }

    int find(const char *key) {
        if (*key == 0) return 0;
        int idx = *key - 'a';
        if (child > 1 || (child == 1 && finish)) return nxt[idx] -> find(key + 1) + 1;
        else return nxt[idx] -> find(key + 1);
    }
};

char ipt[100005][81];

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        Trie *root = new Trie();
        for (int i = 0; i < N; i++) {
            scanf("%s", ipt[i]);
            root -> insert(ipt[i]);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret += root -> find(ipt[i]);
            if (root -> child == 1) ret++;
        }
        double ans = double(ret) / double(N);
        printf("%.2lf\n", ans);
        delete root;
    }
}