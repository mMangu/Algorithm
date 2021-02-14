#include <cstdio>
#include <algorithm>

using namespace std;
int d[1003][3];
int tmp[10];
int main(){
    int N; scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
        d[i][0] = min(d[i-1][1], d[i-1][2]) + tmp[0]; 
        d[i][1] = min(d[i-1][0], d[i-1][2]) + tmp[1]; 
        d[i][2] = min(d[i-1][0], d[i-1][1]) + tmp[2]; 
    }
    printf("%d",min(d[N][0], min(d[N][1],d[N][2])));
}