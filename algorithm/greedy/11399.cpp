#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1003], ans;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        arr[i + 1] += arr[i];
        ans += arr[i];
    }
    printf("%d", ans);
}