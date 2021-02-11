#include <cstdio>
using ll = long long;
ll d[102];
ll dp(int N){
    if (N == 1 || N == 2 || N == 3) return 1;
    if (d[N]) return d[N];
    return d[N] = dp(N-2) + dp(N-3);
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N; scanf("%d",&N);
        printf("%lld\n",dp(N));
    }
}