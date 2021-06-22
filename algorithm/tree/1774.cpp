#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pdll = pair<double, pll>;

pll arr[1003];
ll N, M, par[1003], cnt, lev[1003];
priority_queue<pdll, vector<pdll>, greater<pdll>> pq;

ll dist(pll a, pll b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return false;
    if (lev[a] > lev[b]) swap(a, b);
    if (lev[a] == lev[b]) lev[a]++;
    par[a] = b;
    return true;
}

int main() {
    scanf("%lld %lld", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld %lld", &arr[i].first, &arr[i].second);
        par[i] = i;
        lev[i] = 1;
    }
    for (int i = 1; i <= N; i++) 
        for (int j = i + 1; j <= N; j++) 
            pq.push({dist(arr[i], arr[j]), {i, j}});

    for (int i = 0; i < M; i++) {
        ll a, b; scanf("%lld %lld", &a, &b);
        if (merge(a, b)) cnt++;
    }

    double ans = 0;
    while (!pq.empty() && cnt != N - 1) {
        double d = pq.top().first;
        auto [x, y] = pq.top().second;
        pq.pop();
        if (merge(x, y)) {
            ans += sqrt(d); cnt++;
        }
    }
    printf("%.2lf", ans);
}