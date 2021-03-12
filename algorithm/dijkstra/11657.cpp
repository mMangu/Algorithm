//다익스트라는 음의 가중치에 쓰면 안되는데 그걸 모르고 다익스트라로 접근함
//실패한 코드

#define INF 2e9
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> v[502];
int d[502], cnt;
int check[502];

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a,b,c; scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
    }
    for (int i = 2; i <= N; i++) d[i] = INF;
    priority_queue <pair<int, int>> q;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int distance = -q.top().first;
        int cur = q.top().second;
        q.pop();
        if (distance > d[cur]) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            check[next]++;
            int newDistance = v[cur][i].second + distance;
            if (check[next] >= 3000) {
                printf("-1");
                return 0;
            }
            if (newDistance < d[next]) {
                d[next] = newDistance;
                q.push(make_pair(-newDistance, next));
            }
        }
    }
    for (int i = 2; i <= N; i++) 
        if(d[i] >= INF) printf("-1\n");
        else printf("%d\n", d[i]);
}
