#include <cstdio>
#include <algorithm>
#define INF 2e9

using namespace std;

int arr[102];

void rever(int i, int j) {
    if (i > j) return;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    rever(i + 1, j - 1);
}
int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N; scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", arr + i);
        }
        int ans = 0;
        for (int i = 1; i < N; i++) {
            int right, tmp = INF, idx = 0;
            for (int j = i; j <= N; j++) {
                tmp = min(tmp, arr[j]);
            }
            for (int j = i; j <= N; j++)
                if (tmp == arr[j]) idx = j;
            right = idx;
            rever(i, right);
            ans = ans + right - i + 1;
        }
        printf("Case #%d: %d\n", t, ans);
    }
}