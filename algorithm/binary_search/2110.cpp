#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[200005], N, C;

int count(int mid) {
    int tmp = arr[0], cnt = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] - tmp >= mid) {
            tmp = arr[i];
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    int l = 1, r = arr[N - 1], ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (count(mid) >= C) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", ans);
}