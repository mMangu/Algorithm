#include <cstdio>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    while (n--) {
        int ipt; scanf("%d", &ipt);
        s.insert(ipt);
    }
    while (m--) {
        int ipt; scanf("%d", &ipt);
        s.erase(ipt);
    }
    printf("%lu\n", s.size());
    for (auto iter : s) {
        printf("%d ", iter);
    }
}