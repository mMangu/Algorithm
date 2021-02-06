#include <cstdio>
int A[2003][2003];
int B[2003][2003];
int main(void){
    int N,M; scnaf("%d %d",&N,&M);
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            scanf("%d",A[i][j]);
        }
    }
    for(int i = 0;i < M/2;i++){
        for(int j = 0; j < N; j++){
            B[i][j] = 0;
        }
    }
}