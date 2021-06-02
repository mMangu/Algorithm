#include <cstdio>

int counting[10004];

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp; scanf("%d", &tmp);
        counting[tmp]++;
    }
    for (int i = 0; i < 10004; i++) {
        while (counting[i]--)
            printf("%d\n", i);
    }
}