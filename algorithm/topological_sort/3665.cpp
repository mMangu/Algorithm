#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int g[555][555];

void solve() {
	memset(g, 0, sizeof g);
	int n; cin >> n; v.resize(n);
	for (auto &i : v) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			g[v[i]][v[j]] = 1;
		}
	}
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		swap(g[a][b], g[b][a]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (g[v[j]][v[i]]) swap(v[i], v[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (g[v[j]][v[i]]) {
				cout << "IMPOSSIBLE\n";
                return;
			}
		}
	}
	for (auto i : v) cout << i << " ";
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}