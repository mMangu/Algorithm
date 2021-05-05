#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;

const int INF = 2e9;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int solve(int l, int r) {
    int cnt = r - l + 1, ans = INF;
    if (cnt <= 3) {
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ans = min(ans, dist(v[i], v[j]));
            }
        }
    } else {
        int mid = (l + r) / 2;
        int leftDist = solve(l, mid - 1);
        int rightDist = solve(mid + 1, r);
        ans = min(leftDist, rightDist);
        
        vector<pair<int, int>> tmp;
        tmp.push_back( {v[mid].second, v[mid].first} );

        for (int i = mid - 1; i >= l; i--) {
            if (dist( {v[mid].first, 0}, {v[i].first, 0} ) >= ans) break;
            tmp.push_back( {v[i].second, v[i].first} );
        }

        for (int i = mid + 1; i <= r; i++) {
            if (dist( {v[mid].first, 0}, {v[i].first, 0} ) >= ans) break;
            tmp.push_back( {v[i].second, v[i].first} );
        }

        sort(tmp.begin(), tmp.end());
        
        for (int i = 0; i < tmp.size() - 1; i++) {
            for (int j = i + 1; j < tmp.size(); j++) {
                if ((tmp[i].first - tmp[j].first) * (tmp[i].first - tmp[j].first) >= ans) break;
                ans = min(ans, dist(tmp[i], tmp[j]));
            }
        }
    }
    return ans;
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y; scanf("%d %d", &x, &y);
        v.push_back( {x, y} );
    }
    sort(v.begin(), v.end(), compare);
    printf("%d", solve(0, N - 1));
}