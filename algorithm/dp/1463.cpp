#include <cstdio>
#include <algorithm>

using namespace std;

int d[1000006];

int main() {
    int n; scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        d[i] = 1e6;
    d[n] = 0;
    for (int i = n; i > 0; i--) {
        if (d[i] == 1e6) continue;
        if (i % 2 == 0)
            d[i / 2] = min(d[i] + 1, d[i / 2]);
        if (i % 3 == 0)
            d[i / 3] =  min(d[i] + 1, d[i / 3]);
        d[i - 1] = min(d[i] + 1, d[i - 1]);
    }
    printf("%d",d[1]);
}
