#include <cstdio>

int arr[100005], ans;

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    int start = 0, end = 0, sum = arr[0];
    while (end < N) {
        if (sum == M) {
            ans++;
            sum -= arr[start];
            start++;
        } else if (sum > M) {
            sum -= arr[start];
            start++;
        } else {
            end++;
            sum += arr[end];
        }
    }
    printf("%d", ans);
}