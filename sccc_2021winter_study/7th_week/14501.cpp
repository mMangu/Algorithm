#include <cstdio>
#include <algorithm>
using namespace std;

int d[100], t[100], p[100];

int main() {
    int N; scanf("%d",&N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d",t+i, p+i);
        for (int j = i; j <= N + 1; j++)
            d[j + t[i]] = max(d[j + t[i]], d[i] + p[i]);
    }
    //for (int i = 1; i <= N + 1; i++)
        printf("%d ",d[N + 1]);
}