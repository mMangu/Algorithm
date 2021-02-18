#include <cstdio>
int main(){
    int G; scanf("%d",&G);
    int cnt = 0;
    for (int i = 1; i <= G; i++) {
        if (G % i == 0 && G / i < i) {
            int A = i; int B = G / i;
            if((A + B) % 2 == 0){
                printf("%d\n", (A + B) / 2);
                cnt++;
            }
        }
    }
    if(!cnt)
        printf("-1");
}