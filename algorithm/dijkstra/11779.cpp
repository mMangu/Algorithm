#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> v[1003];
vector<ll> ans;
priority_queue<pll> pq;
ll dist[1003], prv[1003];
const ll INF = 1e9;

int main() {
    ll n, m; scanf("%lld %lld", &n, &m);
    for (ll i = 0; i < m; i++) {
        ll s, e, cost; scanf("%lld %lld %lld", &s, &e, &cost);
        v[s].push_back({e, cost});
    }

    for (ll i = 1; i <= n; i++) dist[i] = INF;
    for (ll i = 1; i <= n; i++) prv[i] = -1;

    ll from, to; scanf("%lld %lld", &from, &to);
    pq.push({0, from});
    dist[from] = 0;
    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        cost = -cost;
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto i : v[now]) {
            ll next = i.first;
            ll nextCost = cost + i.second;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({-nextCost, next});
                prv[next] = now;
            }
        }
    }
    printf("%lld\n", dist[to]);
    // for (ll i = 1; i <= n; i++) printf("%lld ", prv[i]);
    ll cur = to;
    while (cur != -1) {
        ans.push_back(cur);
        cur = prv[cur];
    }
    printf("%lu\n", ans.size());
    for (ll i = ans.size() - 1; i >= 0; i--) printf("%lld ", ans[i]);
}