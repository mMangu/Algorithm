#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

char input[20];
int ans = -2147483648, N;
int cal(int a, char b, int c) {
    if (b == '+') return a + c;
    else if (b == '-') return a - c;
    else return a * c;
}

void dfs(int idx, int cur) {
    char oper = (idx == 0) ? '+' : input[idx - 1];
    if (idx >= N) {
        ans = max(ans, cur);
        return;
    } 
    if (idx + 2 < N)
        dfs(idx + 4, cal(cur, oper, cal(int(input[idx] - '0'), input[idx+1], int(input[idx+2] - '0'))));
    dfs(idx + 2, cal(cur, oper, int(input[idx] - '0')));

}

int main() {
    scanf("%d", &N);
    scanf("%s",input);
    dfs(0, 0);
    printf("%d",ans);
}
