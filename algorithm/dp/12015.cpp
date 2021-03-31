#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 2e9

using namespace std;

int arr[1000006];
vector <int> v;
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    v.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
        } else {
            auto iter = lower_bound(v.begin(), v.end(), arr[i]);
            v[iter - v.begin()] = arr[i];
        }
    }
    printf("%lu", v.size() - 1);
}