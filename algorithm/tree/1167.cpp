#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[100005];
bool check[100005];
int cost[100005];
int ansNode = 0, ansCost = 0;

void bfs(int start) {
    fill_n(check, 100000, 0);
    fill_n(cost, 100000, 0);
    ansNode = 0, ansCost = -1e9;
    queue<int> q;
    q.push(start);
    check[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int y = v[x][i].first;
            if (!check[y]) {
                q.push(y);
                cost[y] = cost[x] + v[x][i].second;
                check[y] = true;
                if (cost[y] > ansCost) {
                    ansCost = cost[y];
                    ansNode = y;
                }
            }
        }
    }
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int s; scanf("%d", &s);
        while (true) {
            int e; scanf("%d", &e);
            if (e == -1) break;
            int dist; scanf("%d", &dist);
            v[s].push_back({e, dist});
        }
    }
    bfs(1);
    bfs(ansNode);
    printf("%d", ansCost);
}