#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2e9

using namespace std;

vector <pair<pair <int, int>, int>> graph[102];
priority_queue <pair<pair<int, int>, int>> q;
int dp[102][10004];
int N, M, K;

int dijkstra(int start) {
    while (!q.empty()) q.pop();
    dp[start][0] = 0;
    q.push(make_pair(make_pair(0, 0), start));
    while (!q.empty()) {
        int curDist = -q.top().first.first;
        int curCost = -q.top().first.second;
        int cur = q.top().second;
        q.pop();
        if (dp[cur][curCost] < curDist || curCost > M) continue;
        if (cur == N) return curDist;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first.first;
            int newDist = graph[cur][i].second + curDist;
            int newCost = graph[cur][i].first.second + curCost;
            if (dp[next][newCost] > newDist && newCost <= M) {
                dp[next][newCost] = newDist;
                q.push(make_pair(make_pair(-newDist, -newCost), next));
            } 
        }
    }
    return 0;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 1; i <= N; i++) graph[i].clear();
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                dp[i][j] = INF;
        for (int i = 0; i < K; i++) {
            int u, v, c, d; scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u].push_back(make_pair(make_pair(v, c), d));
        }
        int ans = dijkstra(1);
        if (ans) printf("%d\n", ans);
        else printf("Poor KCM\n");
    }
}