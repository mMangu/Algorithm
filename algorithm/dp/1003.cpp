#include <cstdio>

int d_1[41] = {0,};
int d_0[41] = {0,};

int dp_0(int x){
    if(x == 1) return 0;
    if(x == 0) return 1;
    if(d_0[x] != 0) return d_0[x];
    return d_0[x] = dp_0(x-1) + dp_0(x-2);
}

int dp_1(int x){
    if(x == 1) return 1;
    if(x == 0) return 0;
    if(d_1[x] != 0) return d_1[x];
    return d_1[x] = dp_1(x-1) + dp_1(x-2);
}


int main(){
    int N; scanf("%d",&N);
    while(N--){
        int x;scanf("%d",&x);
        printf("%d %d\n",dp_0(x),dp_1(x));
    }
}