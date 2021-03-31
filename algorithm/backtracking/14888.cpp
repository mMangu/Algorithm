#include <cstdio>
#include <algorithm>

using namespace std;

int arr[102], p, s, m, d, ans_min = 1e9, ans_max = -1e9;

void solve(int idx, int num) {
    if (!p && !s && !m && !d) {
        ans_min = min(num, ans_min);
        ans_max = max(num, ans_max);
        return;
    } 
    if (p) {
        p--;
        solve(idx + 1, num + arr[idx]);
        p++;
    }
    if (s) {
        s--;
        solve(idx + 1, num - arr[idx]);
        s++;
    }
    if (m) {
        m--;
        solve(idx + 1, num * arr[idx]);
        m++;
    }
    if (d) {
        d--;
        solve(idx + 1, num / arr[idx]);
        d++;
    }
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    scanf("%d %d %d %d", &p, &s, &m, &d);
    solve(1, arr[0]);
    printf("%d\n%d", ans_max, ans_min);
}