#include <cstdio>
#include <algorithm>
bool binarysearch(int *arr,int len,int key);
using namespace std;

int A[100005];

int main(void){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d", A + i);
    int M; scanf("%d",&M);
    sort(A, A + N);
    for (int i = 0; i < M; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(binarysearch(A, N, tmp) == true)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

bool binarysearch(int *arr,int len,int key){
    int l = 0, r = len - 1, mid;
    while(r - l >= 0)
    {
        mid = (l + r) / 2;
        if(arr[mid] == key){
            return true;
        }
        else if(arr[mid] > key){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }  
    }
    return false;
}