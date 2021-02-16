#include <cstdio>
#include <algorithm>
int d[1003];
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int N; scanf("%d",&N);
    for (int i = 2; i <= N; i++)
        d[i] = 2e9;
    for (int i = 1; i <= N; i++) {
        int a; scanf("%d",&a);
        for (int j = 1; j <= a; j++) {
            d[i + j] = min(d[i] + 1, d[i + j]);
        }
    }
    if(d[N] == 2e9)
        printf("-1");
    else
        printf("%d",d[N]);
}