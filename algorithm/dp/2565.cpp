#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> arr[102], dp[102];
const int INF = 2e9;
vector <int> v;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr+ N);
    v.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (arr[i].second > v.back()) v.push_back(arr[i].second);
        else {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), arr[i].second);
            v[iter - v.begin()] = arr[i].second;
        }
    }
    int ans = N - v.size() + 1;
    printf("%d", ans);
}