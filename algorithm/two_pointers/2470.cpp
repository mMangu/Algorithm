#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
int arr[100005];

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    ll l = 0, r = N - 1, sum = 0, ansL, ansR, ans = 2e10;
    while (l < r) {
        sum = arr[l] + arr[r];
        if (ans > abs(sum)) {
            ansL = arr[l];
            ansR = arr[r];
            ans = abs(sum);
        }
        if (sum < 0) l++;
        else r--;
    }
    printf("%lld %lld", ansL, ansR);
}
