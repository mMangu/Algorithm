#include <cstdio>

int main(void){
    while(1){
        int node[1003] = {-1, }, p[1003] = {-1,}, k_idx = -1,cnt = -1;
        int n,k; scanf("%d %d",&n,&k);
        if(n == 0 && k == 0) return 0;
        for(int i = 1; i <= n;i++){
            scanf("%d",node + i);
            if(node[i] == k) 
                k_idx = i;
            if(node[i] != node[i-1] + 1) cnt++;
            p[i] = cnt;
        }
        int output = 0;
        for(int i = 1; i <= n; i++)
            if(p[i] != p[k_idx] && p[p[i]] == p[p[k_idx]]) output++;
        printf("%d\n",output);
    }
}