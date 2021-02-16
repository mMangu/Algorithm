#include <cstdio>
#include <queue>
using namespace std;

bool map[102][102];
int check[102][102];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int bfs(int start, int end);

int main(){
    int N,M; scanf("%d %d",&N,&M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int tmp; scanf("%1d", &tmp);
            if (tmp == 1) map[i][j] = true;
        }
   // for(int i = 1; i <= N * M; i++)
  //      printf("%d ",arr[i]);
    printf("%d", bfs(N,M));    
}


int bfs(int N, int M) {
    int y = 0, x = 0;
    queue <pair<int, int>> q;
    q.push(make_pair(y,x));
    check[y][x] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == N -1 && x == M -1) break;
        for (int i = 0; i < 4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            if(!check[nextY][nextX] && map[nextY][nextX]){
                q.push(make_pair(nextY,nextX));
                check[nextY][nextX] = check[y][x] + 1;
            }
        }
    }
    return check[N-1][M-1];
}