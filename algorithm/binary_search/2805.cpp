#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

ll tree[1000006], N, M;

ll cut(ll mid) {
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
        if (tree[i] - mid > 0)
            cnt += tree[i] - mid;
    }
    return cnt;
}

bool check(ll mid) {
    if (cut(mid) >= M) return true;
    else return false;
}
int main() {
    scanf("%lld %lld", &N, &M);
    for (ll i = 0; i < N; i++) 
        scanf("%lld", tree + i);
    sort(tree, tree + N);
    ll l = 0, r = tree[N - 1];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld", r);
}