#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

ll cost[100005], dist[100005], MIN = 2e9, ans;

int main() {
    ll N; scanf("%lld", &N);
    for (int i = 0; i < N - 1; i++) scanf("%lld", dist + i);
    for (int i = 0; i < N; i++) scanf("%lld", cost + i);
    for (int i = 0; i < N; i++) {
        if (cost[i] < MIN) MIN = cost[i];
        ans += MIN * dist[i];
    }      
    printf("%lld", ans);
}
