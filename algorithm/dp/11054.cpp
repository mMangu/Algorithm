#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dLeft[1002], dRight[1002], arr[1002];
const int INF = 2e9;

vector <int> vLeft;
vector <int> vRight;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    vLeft.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (arr[i] > vLeft.back()) vLeft.push_back(arr[i]);
        else {
            vector<int>::iterator low = lower_bound(vLeft.begin(), vLeft.end(), arr[i]);
            vLeft[low - vLeft.begin()] = arr[i];
        }
        dLeft[i] = vLeft.size() - 1;
    }
    vRight.push_back(-INF);
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] > vRight.back()) vRight.push_back(arr[i]);
        else {
            vector<int>::iterator low = lower_bound(vRight.begin(), vRight.end(), arr[i]);
            vRight[low - vRight.begin()] = arr[i];
        }
        dRight[i] = vRight.size() - 1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, dLeft[i] + dRight[i] - 1);
    printf("%d", ans);
}