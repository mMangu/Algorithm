#define INF 2e9
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int d_s[2002], d_g[2002], d_h[2002];
vector <pair<int, int>> v[2002];

void dijkstra(int start, int d[]) {
    for (int i = 1; i <= 2002; i++)
        d[i] = INF;
    d[start] = 0;
    priority_queue <pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (distance > d[cur]) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int newDistance = d[cur] + v[cur][i].second;
            if (newDistance < d[next]) {
                d[next] = newDistance;
                pq.push(make_pair(-newDistance, next));
            }
        }
    }
}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, m, t; scanf("%d %d %d", &n, &m, &t);
        int s, g, h; scanf("%d %d %d", &s, &g, &h);

        for(int i = 1; i <= n; i++)
            v[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, d; scanf("%d %d %d", &a, &b, &d);
            v[a].push_back(make_pair(b, d));
            v[b].push_back(make_pair(a, d));
        }
        priority_queue <int> destination;
        for (int i = 0; i < t; i++) {
            int tmp; scanf("%d", &tmp);
            destination.push(-tmp);
        }
        dijkstra(s, d_s);
        dijkstra(g, d_g);
        dijkstra(h, d_h);
        int firstDestionation, check;
        if (d_s[g] < d_s[h]) {
            check = 0;
            firstDestionation = g;
        } else {
            check = 1;
            firstDestionation = h;
        }
        for (int i = 0; i < t; i++) {
            int candidate = -destination.top();
            destination.pop();
            int route;
            if (!check) route = d_s[firstDestionation] + d_g[h] + d_h[candidate];
            else route = d_s[firstDestionation] + d_h[g] + d_g[candidate];
            if (d_s[candidate] == route) printf("%d ", candidate);
        }
        printf("\n");
     }
}