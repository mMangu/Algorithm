#include <cstdio>
#include <algorithm>

using namespace std;

int arr[302], d[302];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    d[0] = arr[0];
    d[1] = max(d[0] + arr[1], arr[1]);
    d[2] = max(d[0] + arr[2], arr[1] + arr[2]);
    for (int i = 3; i < n; i++) {
        d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i] + arr[i - 1]);
    }
    printf("%d",d[n -1]);
    return 0;
}