#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

bool prime[4000006];
vector <int> arr;
int main() {
    int N; scanf("%d", &N);
    for (ll i = 2; i <= N; i++) {
        if (!prime[i])
            for (ll j = i * i; j <= N; j += i)
                prime[j] = true;
    }
    for (int i = 2; i <= N; i++)  
        if (!prime[i]) arr.push_back(i);
    arr.push_back(0); //20 행에서 ++r 할때 범위 넘어가서 런타임 에러 방지
    ll l = 0, r = 0, sum = arr[0], ans = 0;
    while (r < arr.size() - 1) {
        if (sum < N) sum += arr[++r];
        else if (sum > N) sum -= arr[l++];
        else { 
            ans++;
            sum -= arr[l++];
        }
    }
    printf("%lld", ans);
}