#include <cstdio>
#include <set>

using namespace std;

set<int> A, B;
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int ans = n + m;
    while (n--) {
        int ipt; scanf("%d", &ipt);
        A.insert(ipt);
    }
    while (m--) {
        int ipt; scanf("%d", &ipt);
        B.insert(ipt);
    }
    for (auto iter : A) {
        if (B.contains(iter)) ans -= 2; 
    }
    printf("%d", ans);
}