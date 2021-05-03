#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[10004];
bool check[10004];
int cost[10004];
int ansNode, ansCost;

void bfs(int start) {
    fill_n(check, 10004, false);
    fill_n(cost, 10004, 0);
    ansNode = 0, ansCost = 0;
    
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
                if (cost[y] >= ansCost) {
                    ansCost = cost[y];
                    ansNode = y;
                }
            }
        }
    }
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int s, e, dist; scanf("%d %d %d", &s, &e, &dist);
        v[s].push_back({e, dist});
        v[e].push_back({s, dist});
    }
    bfs(1);
    bfs(ansNode);
    printf("%d", ansCost);
}