#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int visited[10004], s, e;

string BFS(void)
{
    queue<pair<int, string>> q;
    q.push({s, ""});
    visited[s] = true;
    while (!q.empty())
    {
        int num = q.front().first;
        string change = q.front().second;
        q.pop();
        if (num == e) return change;
        int curNum = (2 * num) % 10000;
        if (!visited[curNum]) {
            visited[curNum] = true;
            q.push(make_pair(curNum, change + "D"));
        }
        curNum = (num - 1) < 0 ? 9999 : num - 1;
        if (!visited[curNum]) {
            visited[curNum] = true;
            q.push(make_pair(curNum, change + "S"));
        }
        curNum = (num % 1000) * 10 + num / 1000;
        if (!visited[curNum]) {
            visited[curNum] = true;
            q.push(make_pair(curNum, change + "L"));
        }
        curNum = (num % 10) * 1000 + (num / 10);
        if (!visited[curNum]) {
            visited[curNum] = true;
            q.push(make_pair(curNum, change + "R"));
        }
    }
    return "";
}

int main() {
   int N; scanf("%d", &N);
   while (N--) {
       memset(visited, false, sizeof(visited));
       scanf("%d %d", &s, &e);
       cout << BFS() << endl;
    } 
}