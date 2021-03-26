#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

void init(vector <ll> &arr, vector <ll> &tree, ll node, ll start, ll end) {
    if (start == end) tree[node] = start;
    else {
        ll mid = (start + end) / 2;
        init(arr, tree, node * 2, start, mid);
        init(arr, tree, node * 2 + 1, mid + 1, end);
        if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
    }
}

ll query(vector <ll> &arr, vector <ll> &tree, ll node, ll start, ll end, ll i, ll j ) {
    if (end < i || start > j) return -1;
    else if (i <= start && end <= j) return tree[node];
    ll mid = (start + end) / 2;
    ll left = query(arr, tree, node * 2, start, mid, i, j);
    ll right = query(arr, tree, node * 2 + 1, mid + 1, end, i, j);
    if (left == -1) return right;
    else if (right == -1) return left;
    else if (arr[left] < arr[right]) return left;
    else return right;
}


ll solve(vector <ll> &arr, vector <ll> &tree, ll start, ll end) {
    ll N = arr.size() - 1;
    ll idx = query(arr, tree, 1, 1, N, start, end);
    ll ans = (end - start + 1) * arr[idx];
    if (start < idx) {
        ll tmp = solve(arr, tree, start, idx - 1);
        ans = max(ans, tmp);
    }
    if (idx < end) {
        ll tmp =  solve(arr, tree, idx + 1, end);
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    while (true) {
        ll N; scanf("%lld", &N);
        if (N == 0) return 0;
        vector <ll> arr(N + 1);
        for (int i = 1; i <= N; i++) {
            ll tmp; scanf("%lld", &arr[i]);
        }
        ll height = (int)ceil(log2(N));
        ll tree_size = (1 << (height + 1));
        vector <ll> tree(tree_size);
        init(arr, tree, 1, 1, N);
        printf("%lld\n", solve(arr, tree, 1, N));
    }
    return 0;
}
