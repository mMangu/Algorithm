#include <cstdio>
#include <algorithm>

using namespace std;

int arr[502][502];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int tmp, check;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if(!check)
                arr[i + 1][j] += arr[i][j];
            check = 0;
            if (arr[i][j] > arr[i][j + 1]) {           
                arr[i + 1][j + 1] += arr[i][j]; 
                check = 1;
            }
        }
        check  = 0;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans =  max(ans,arr[n-1][i]);
    printf("%d",ans);
}