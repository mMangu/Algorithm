#include <cstdio>
#include <algorithm>

int a[30004];

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int c0 = 0, c1 = 0, c2 = 0;
        int N; scanf("%d", &N);
        for (int i = 0; i < N; i++) { 
            int tmp; scanf("%d", &tmp);
            a[i] = tmp % 3;
            if (a[i] == 0) c0++;
            else if (a[i] == 1) c1++;
            else c2++;
        }
        sort(a, a + N);
        //printf("%d %d %d\n", c0, c1, c2);
        int ans = 0;
        while (c0 != c1 || c1 != c2) {
            //printf("%d %d %d\n", c0, c1, c2);
            //int r; scanf("%d", &r);
            if (c0 < N / 3) {
                a[N - 1] = 0;
                c0++; c2--;
                ans++;
            } else if (c1 < N / 3) {
                a[0]++;
                c0--; c1++;
                ans++;
            } else if (c2 < N / 3) {
                a[c0]++;
                c2++; c1--;
                ans++;
            } else if (c1 )
            sort(a, a + N);
        }
        printf("%d\n", ans);
    }
}