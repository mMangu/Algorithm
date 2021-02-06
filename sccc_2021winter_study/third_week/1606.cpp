#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int main(void){
    ll x,y; scanf("%lld %lld",&x,&y);
    ll n;
    if(x == 0 && y == 0){
        printf("1");
        return 0;
    }
    //n 번째 껍데기인지 찾기
    if(x * y >= 0) // x y 부호 같을 때
        n = abs(x + y);
    else
        n = max(abs(x),abs(y));
    ll cnt;
    if(x >= 0 && y == 1){
        n = x + y;
        cnt = 3*n*(n - 1) + 1 + 1;
        printf("%lld",cnt);
        return 0;
    }
    //1 6 12 18 ... 인 등차수열합 + 1
    cnt = 3*n*(n - 1) + 1 + 1;
    int a = n - 1, b = 1;
    //n번째 껍데기 시작부터 모두 돌면서 확인
    while(a > 0){
        a--;
        b++;
        cnt++;
        if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
        }
    }
    while(a > -n){
        a--;
        cnt++;
         if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
         }
    }
    while(b > 0){
        b--;
        cnt++;
         if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
         }
    }
    while(a < 0){
        a++;
        b--;
        cnt++;
        if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
        }
    }
    while(a < n){
        a++;
        cnt++;
        if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
        }
    }
    while(b < 0){
        b++;
        cnt++;
        if(a == x && b == y){
            printf("%lld",cnt);
            return 0;
        }
    }
}