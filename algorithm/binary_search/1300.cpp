#include <cstdio>

int N, K;

int count(int mid) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (mid / i >= N) cnt += N;
        else cnt += mid / i;
    }
    return cnt;
}
int main() {
    scanf("%d %d", &N, &K);
    int l = 1, r = K, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        //printf("%d %d %d %d\n",l, r, mid, count(mid));
        if (count(mid) >= K) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d", ans);
}