#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N, C, ans;

void permutaion(ll idx, ll sum, vector <ll> &v, vector <ll> &save) {
    if (idx == v.size()) {
        if (sum <= C) save.push_back(sum);
        return;
    } else {
        permutaion(idx + 1, sum + v[idx], v, save);
        permutaion(idx + 1, sum, v, save);
        return;
    }
}

int main() {
    vector <ll> A, B, perA, perB;
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N / 2; i++) {
        int tmp; scanf("%d", &tmp);
        A.push_back(tmp);
    }
    for (int i = 0; i < N - (N / 2); i++) {
        int tmp; scanf("%d", &tmp);
        B.push_back(tmp);
    }
    permutaion(0, 0, A, perA);
    permutaion(0, 0, B, perB);
    sort(perB.begin(), perB.end());

    for (int i = 0; i < perA.size(); i++) {
        int l = -1, r = perB.size(), key = C - perA[i];
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (key < perB[mid]) r = mid;
            else l = mid;
            //printf("%d %d %d %d %d\n", l, r, mid, key, perB[mid]);
        }
        //printf("%d ", r);
        //printf("\n");
        ans += r;
    }
    printf("%d", ans); 
}