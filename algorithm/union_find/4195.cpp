#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int par[200005], mapSize[200005];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return;
    if (mapSize[a] > mapSize[b]) swap(a, b);
    par[a] = b;
    mapSize[b] += mapSize[a];
    mapSize[a] = 0;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i = 0; i <= 2 * N; i++) {
            par[i] = i;
            mapSize[i] = 1;
        }

        map<string, int> m;
        int idx = 1;

        while (N--) {
            string a, b; cin >> a >> b;
            if (!m.count(a)) m[a] = idx++;
            if (!m.count(b)) m[b] = idx++;
            int parA = find(m[a]), parB = find(m[b]);
            if (parA == parB) {
                cout << max(mapSize[parA], mapSize[parB]) << "\n";
            } else {
                merge(parA, parB);
                cout << max(mapSize[parA], mapSize[parB]) << "\n";
            }
        }
    }
}