#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005], ans;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    int x; scanf("%d", &x);
    sort(arr, arr + N);
    int l = 0, r = N - 1;
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            l++;
            ans++;
        }
        else if (arr[l] + arr[r] > x) r--;
        else l++;
    }
    printf("%d", ans);
}