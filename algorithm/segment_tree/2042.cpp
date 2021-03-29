#include <cstdio>

using ll = long long;

ll arr[1000006];
ll tree[4000006];

ll init(ll node, ll start, ll end) {
    if (start == end) return tree[node] = arr[start];
    ll mid = (start + end) / 2;
    ll left = init(node * 2, start, mid);
    ll right = init(node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
}

ll sum(ll node, ll start, ll end, ll left, ll right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    ll mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(ll start, ll end, ll node, ll index, ll dif) {
    if (index < start || index > end) return;
    tree[node] += dif;
    if (start == end) return;
    ll mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    ll N, M, K; scanf("%lld %lld %lld", &N, &M, &K);
    for (ll i = 0; i < N; i++)
        scanf("%lld", arr + i);
    init(1, 0, N - 1);
    for (ll i = 0; i < M + K; i++) {
        ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            ll dif = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, N - 1, 1, b - 1, dif);
        } else {
            printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
        }
    }
}