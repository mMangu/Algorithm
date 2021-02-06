#include <cstdio>
#include <algorithm>

using namespace std;

bool check_left(int mid,int tmp);
bool check_right(int mid,int tmp);
int tmp[500005],*A = tmp + 1;
int main(void){
    int N;scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",A + i);
    }
    sort(A, A+N);
    A[-1] = -1e7 - 1;
    A[N] = 1e7 + 1;
    int M; scanf("%d",&M);
    while(M--){
        int tmp; scanf("%d",&tmp);
        int left,right;
        int l = -1, r = N, mid;
        while(l + 1 < r){
            mid = (r + l) / 2;
            if(check_left(mid,tmp))
                r = mid;
            else
                l = mid;
        }
        left = l;
        l = -1, r = N;
        while(l + 1 < r){
            mid = (r + l) / 2;
            if(check_right(mid,tmp))
                r = mid;
            else
                l = mid;
        }
        right = r;
        printf("%d ",right - left -1);
    }
    return 0;
}

bool check_left(int mid,int tmp){
    if(A[mid] >= tmp)
        return true;
    else
        return false;
}

bool check_right(int mid,int tmp){
    if(A[mid] > tmp)
        return true;
    else
        return false;
}