#include <cstdio>

int d[1000006] = {0,};
int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(d[x]) return d[x];
    return d[x] = (dp(x-1) + dp(x-2)) % 15746;
}
int main(void){
    int N; scanf("%d",&N);
    printf("%d",dp(N));
}