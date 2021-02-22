#include <cstdio>
#include <algorithm>

using namespace std;

int input[300], output[300], N, M;

bool check_M(int k) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + input[i];
        if (sum > k) {
            cnt++;
            sum = input[i];
        }
    }
    if (cnt <= M) return true;
    else return false;
}

int main() {
    int l = 0, r = 0, k;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", input + i);
        r = r + input[i];
        l = max(l,input[i]);
    }
    //최적의 k찾는 binary search
    while (r >= l) {
        k = (l + r) / 2;
        if (check_M(k))
            r = k - 1;
        else 
            l = k + 1;
    }
    
    printf("%d\n", l);
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + input[i];
        if (sum > l) {
            sum = input[i];
            M--;
            printf("%d ",cnt);
            cnt = 0;
        }
        cnt++;
        if(N - i == M) break;
    }
    while (M--){
        printf("%d ",cnt);
        cnt = 1;
    }
}


// 그룹 합의 최대값을 k라고 할때
// 만약 M == 1 이라고 하면 k는 최대가 된다
// 또한 M == N 이면 K는 최소가 된다
// 이렇듯 k의 값은 M에 대해 단조함수이다
// 그렇기 때문에 k의 값을 고정해놓고 그때 최소 M을 구할 것이다

