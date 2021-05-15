#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

vector<pii> lis;
int arr[1000006], parent[1000006], leaf_idx;
const int INF = 2e9;

bool comp(const pii &a, const pii &b) { return a.first < b.first; }
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    lis.push_back({-INF, -1});
    for (int i = 0; i < N; i++) {
        if (arr[i] > lis.back().first) {
            parent[i] = lis[lis.size() - 1].second;
            lis.push_back({arr[i], i});
            leaf_idx = i;
        } else {
            auto iter = lower_bound(lis.begin(), lis.end(), pii(arr[i], 0) , comp) - lis.begin();
            lis[iter].first = arr[i];
            lis[iter].second = i;
            parent[i] = lis[iter - 1].second;
        }
    }
    printf("%lu\n", lis.size() - 1);
    vector<int> ans;
    while (leaf_idx >= 0) {
        ans.push_back(arr[leaf_idx]);
        leaf_idx = parent[leaf_idx];
    }
    for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
}