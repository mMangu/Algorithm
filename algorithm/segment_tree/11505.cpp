#include <cstdio>
#include <cstring>

#define MOD 1000000007

using ll = long long;

ll arr[1000006], tree[4000006];

ll init(ll node, ll start, ll end) {
    if (start == end) return tree[node] = arr[start];
    ll mid = (start + end) / 2;
    ll left = init(2 * node, start, mid) % MOD;
    ll right = init(2 * node + 1, mid + 1, end) % MOD;
    return tree[node] = (left * right) % MOD;
}

ll multiply(ll node, ll start, ll end, ll left, ll right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    ll mid = (start + end) / 2;
    return ((multiply(2 * node, start, mid, left, right) * multiply(2 * node + 1, mid + 1, end, left, right)) % MOD);
}

ll update(ll index, ll node, ll start, ll end, ll newNum) {
    if (index < start || index > end) return tree[node];
    if (start == end) return tree[node] = newNum;
    ll mid = (start + end) / 2;
    ll left = update(index, 2 * node, start, mid, newNum);
    ll right = update(index, 2 * node + 1, mid + 1, end, newNum);
    return tree[node] = (left * right) % MOD;
}

int main() {
    ll N, M, K; scanf("%lld %lld %lld", &N, &M, &K);
    for (ll i = 0; i < N; i++)
        scanf("%lld", arr + i);
    init(1, 0, N - 1);
    for (ll i = 0; i < M + K; i++) {
        ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            update(b - 1, 1, 0, N - 1, c);
            arr[b - 1] = c;
        }
        else printf("%lld\n", multiply(1, 0, N - 1, b - 1, c - 1));
    }
}