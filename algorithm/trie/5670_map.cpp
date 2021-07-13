#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct Trie {
    bool finish = false;
    int child = 0;
    map<char, Trie> next;

    Trie() : finish(false), child(0) { }

    void insertTrie(const char *key) {
        if (*key == 0) {
            finish = true;
            return;
        }
        if (this -> next.find(*key) == this -> next.end()) {
            this -> next[*key] = Trie();
            child++;
        }
        this -> next[*key].insertTrie(key + 1);
    }

    int search(const char *key) {
        if (*key == 0) return 0;
        if (child > 1 || (child == 1 && finish)) return next[*key].search(key + 1) + 1;
        else return next[*key].search(key + 1);
    }
};

char ipt[100005][81];

int main() {
    int N; while (scanf("%d", &N) > 0) {
        Trie root = Trie();
        for (int i = 0; i < N; i++) {
            scanf("%s", ipt[i]);
            root.insertTrie(ipt[i]);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret += root.search(ipt[i]);
            if (root.child == 1) ret++;
        }
        double ans = double(ret) / double(N);
        printf("%.2lf\n", ans);
    }
}