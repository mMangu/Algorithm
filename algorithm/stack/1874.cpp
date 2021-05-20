#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int arr[100005];

int main() {
    stack<int> s;
    string ans;
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);

    int j = 0;
    for (int i = 1; i <= N; i++) {
        s.push(i);
        ans += '+';
        while (!s.empty() && s.top() == arr[j]) {
            s.pop();
            ans += '-';
            j++;
        }
    }
    if (!s.empty()) printf("NO");
    else { 
        for (int i = 0; i < ans.length(); i++) {
            printf("%c\n", ans[i]);
        }
    }
}