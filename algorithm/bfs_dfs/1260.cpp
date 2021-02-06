#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool bfs_check[1003];
bool dfs_check[1003];
vector<int> vec[1003];

void dfs(int x);
void bfs(int start);
int main(void){
    int N,M,V; scanf("%d %d %d",&N,&M,&V);
    while(M--){
        int a,b; scanf("%d %d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        sort(vec[i].begin(),vec[i].end());
    }
    dfs(V);
    printf("\n");
    bfs(V);
}

void dfs(int x){
    if(dfs_check[x]) return;
    dfs_check[x] = true;
    printf("%d ",x);
    for(int i = 0; i < vec[x].size();i++){
        int y = vec[x][i];
        dfs(y);
    }
}

void bfs(int start){
    bfs_check[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ",x);
        for(int i = 0; i < vec[x].size();i++){
            int y = vec[x][i];
            if(!bfs_check[y]){
                q.push(y);
                bfs_check[y] = true;
            }
        }
    }
}

