#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> arr[100005];
vector<int> LIS;
int parent[100005];

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (i == 0 || arr[i].second > LIS.back()) {
            LIS.push_back(arr[i].second);
            parent[i] = LIS.size() - 1;
        } else {
            auto idx = lower_bound(LIS.begin(), LIS.end(), arr[i].second) - LIS.begin();
            LIS[idx] = arr[i].second;
            parent[i] = idx;
        }        
    }
    printf("%lu\n", N - LIS.size());
    vector<int> ans;
    int check_ans = LIS.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (parent[i] == check_ans) check_ans--;
        else ans.push_back(arr[i].first);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%d\n", ans[i]);
}