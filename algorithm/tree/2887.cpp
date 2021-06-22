#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

struct T {
    int x, y, z, idx;
};

priority_queue<piii, vector<piii>, greater<piii>> pq;
int N, ans, cnt;
T arr[100005];
int par[100005];

bool compare(T a, T b) {
    if (cnt == 0) return a.x < b.x;
    if (cnt == 1) return a.y < b.y;
    if (cnt == 2) return a.z < b.z;
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[y] = x;
    return true;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
        arr[i].idx = i;
        par[i] = i;
    }
    for (int i = 0; i < 3; i++) {
        sort(arr, arr + N, compare); cnt++;
        for (int j = 0; j < N - 1; j++) {
            int dist = min(abs(arr[j].x - arr[j + 1].x), min(abs(arr[j].y - arr[j + 1].y), abs(arr[j].z - arr[j + 1].z)));
            pq.push({dist, {arr[j].idx, arr[j + 1].idx}});
        }
    }
    while (!pq.empty()) {
        auto [x, y] = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (merge(x, y)) ans += dist;
    }
    printf("%d", ans);
}