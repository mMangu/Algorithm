

#include <iostream>

using namespace std;

int arr[500005], ans[500005];
int flag[500005];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n, t; cin >> n >> t;
        for (int i = 1; i <= n; i++) {
            scanf("%1d", &arr[i]);
            flag[i] = 0;
            ans[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            if (i - t < 1 && i + t <= n) flag[i + t] = (arr[i] ? 1 : -1);
            if (i + t > n && i - t > 0) flag[i - t] = (arr[i] ? 1 : -1);
            else { 
                if (!arr[i] && i + t <= n && i - t > 0) flag[i + t] = flag[i - t] = -1; 
            }
        }

        for (int i = 1; i <= n; i++) if (flag[i] == 1) {
            ans[i] = 1;
        } 

        for (int i = t + 1; i <= n - t; i++) if (arr[i]) {
            if (i + t <= n && ans[i + t]) continue; 
            if (i - t <= n && ans[i - t]) continue; 
            if (i + t <= n && flag[i + t] == -1) ans[i - t] = 1;
            if (i - t > 0 && flag[i - t] == -1) ans[i + t] = 1;
            if (i + t <= n && i - t > 0 && flag[i + t] != -1 && flag[i - t] != -1) ans[i + t] = 1;
        }
		cout << "Case #" << test_case+1 << endl;
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << endl;
	}

	return 0;
}