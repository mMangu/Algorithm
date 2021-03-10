#define INF 2e9
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

ll d_v1[802], d_v2[802], N, E;

vector <pair<ll, ll>> v[802];

void dijkstra(ll start, ll d[]) {
    for (ll i = 1; i <= N; i++) d[i] = INF;
    d[start] = 0;
    priority_queue <pair<ll, ll> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        ll distance =  -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        if (distance > d[cur]) continue;
        for (ll i = 0; i < v[cur].size(); i++) {
            ll next = v[cur][i].first;
            ll newDistance = v[cur][i].second + d[cur];
            if (newDistance < d[next]) {
                d[next] = newDistance;
                pq.push(make_pair(-newDistance, next));
            } 
        }
    }
}

int main() {
    scanf("%lld %lld", &N, &E);
    for (ll i = 0; i < E; i++) {
        ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
            v[a].push_back(make_pair(b, c));
            v[b].push_back(make_pair(a, c));
    }
    ll v1, v2; scanf("%lld %lld", &v1, &v2);
    dijkstra(v1, d_v1);
    dijkstra(v2, d_v2);
    ll ans = min(d_v1[1] + d_v1[v2] + d_v2[N], d_v2[1] + d_v2[v1] + d_v1[N]);
    if (ans >= 2e9) printf("-1");
    else printf("%lld", ans);
}