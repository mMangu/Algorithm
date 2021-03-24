#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
ll cable[10004], N, K, r, l, ans;

int count(ll mid) {
    ll cnt = 0;
    for (ll i = 0; i < K; i++) {
        cnt += cable[i] / mid;
    }
    return cnt;
}

bool check(ll mid) {
    if (count(mid) >= N) return true;
    else return false;
}

int main() {
    scanf("%lld %lld", &K, &N);
    for (ll i = 0; i < K; i++) {
        scanf("%lld", cable + i);
    }
    sort(cable, cable + K);
    ll r = cable[K - 1], l = 1;
    while(l <= r) {
        ll mid = (r + l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld", r);
}