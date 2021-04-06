#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005], ans = 2e9;

int main() {
    int N, S; scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    int l = 0, r = 0, sum = arr[0];
    while (r < N) {
        if (sum < S) {
            sum += arr[++r];
        } else {
            ans = min(ans, r - l + 1);
            sum -= arr[l++];
        }
    }
    if (ans == 2e9) printf("0");
    else printf("%d", ans);
}