#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> graph;
priority_queue<pii> pq;
bool visited[10004];
int k;

void prim(int cur) {
	visited[cur] = true;
	for (auto iter : graph[cur]) {
		auto [x, y] = iter;
		if (!visited[iter.second]) pq.push({-x, y}); 
	}
	while (!pq.empty()) {
		auto [x, y] = pq.top();;
		pq.pop();
		if (!visited[y]) {
			k -= x;
			prim(y);
			return;
		}
	}
}

int main() {
	int v, e; scanf("%d %d", &v, &e);
	graph.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}
	prim(1);
	printf("%d", k);
}