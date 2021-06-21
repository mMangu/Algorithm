#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;
using pdd = pair<double, double>;
using pdi = pair<double, int>;

pdd arr[102];
bool visited[102];
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
int N;
double ans;

double dist(pdd a, pdd b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void prim(int s) {
    visited[s] = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) pq.push({dist(arr[s], arr[i]), i});
    }
    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();
        if (!visited[y]) {
            ans += x;
            prim(y);
            return;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf %lf", &arr[i].first, &arr[i].second);
    prim(0);
    printf("%.2lf", ans);
}