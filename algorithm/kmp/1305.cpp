#include <cstdio>

char s[1000006];
int pi[1000006], L;

int main() {
    scanf("%d %s", &L, s);
    int j = 0;
    for (int i = 1; i < L; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = ++j;
    }
    printf("%d", L - pi[L - 1]);
}