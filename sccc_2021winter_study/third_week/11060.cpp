#include <cstdio>
int D[1003];
int main(void){
    int N; scanf("%d",&N);
    D[1] = 1;
    for(int i=1;i<=N;i++){
        int tmp; scanf("%d",&tmp);
        if(D[i] == 0){
            break;
        }
    }
    printf("%d",cnt);
}