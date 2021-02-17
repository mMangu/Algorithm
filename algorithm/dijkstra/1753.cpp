#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int,int> > vec[20004];
int d[20004], INF = 1e9;
int main() {
    int V,E; scanf("%d %d", &V,&E);
    int K; scanf("%d",&K);
    int a,b,c;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back(make_pair(b,c));
    }
    for (int i = 1; i <= V; i++)
        d[i] = INF;
    d[K] = 0;
    priority_queue <pair<int, int> > q;
    q.push(make_pair(0, K));
    while (!q.empty()) {
        int distance = -q.top().first;
        int cur = q.top().second;
        q.pop();
        if (d[cur] < distance) continue;
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int nextDistance = vec[cur][i].second + distance;
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                q.push(make_pair(-nextDistance,next));
            }
        }
    }   
    for (int i = 1; i <= V; i++) {
        if(d[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",d[i]);
    }
    return 0;
}