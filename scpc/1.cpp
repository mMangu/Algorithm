#include <iostream>
#include <cstring>

using namespace std;

int Answer;
int par[100005], lev[100005];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return;
    if (lev[a] > lev[b]) swap(a, b);
    par[a] = b;
    lev[b] += lev[a];
    lev[a] = 0;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        int N; cin >> N;
        for (int i = 1; i <= N; i++) {
            par[i] = i;
            lev[i] = 1;
        }

        for (int i = 1; i <= N; i++) {
            int ipt; cin >> ipt;
            if (i + ipt <= N) merge(i, i + ipt);
        }

        for (int i = 1; i <= N; i++) {
            if (lev[i]) Answer++;
        }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}