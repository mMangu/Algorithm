#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int output[200005];
int check_friends[200005] = {0,};
bool truth[200005];

vector<int> v[200005];
queue<int> q;

void bfs(int M);
int count_truth(int index);
int main(void){
    int N; scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        while(1){
            int tmp; scanf("%d",&tmp);
            if(tmp == 0) break;
            v[i].push_back(tmp);
            check_friends[i]++; // 주변인이 몇명인지 체크
        }
    }
  
    int M; scanf("%d",&M);
    for(int i = 0; i < M; i++){
        int tmp; scanf("%d",&tmp);
        q.push(tmp);
        truth[tmp] = true;
    }

    bfs(M);

    for(int i = 1; i <= N; i++){
        if(truth[i])
            printf("%d ",output[i]);
        else
            printf("-1 ");        
    }
    return 0;
}

void bfs(int M){
    int check_t = M;
    int t = 0;
    while(!q.empty()){
        //시간이 t일 때 케이스를 검사 한 후 t+1 일때 검사해야할 수를 미리 저장해놓음
        if(!check_t){
            check_t = q.size();
            t++;
        }
        int x = q.front();
        q.pop();
        if(!truth[x]){
            truth[x] = true;
            output[x] = t;
        }
        check_t--;
        for(int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];
            if(!truth[y])
                if(2 * count_truth(y) >= check_friends[y])
                    q.push(y);
        }
    }
}

//index 주변인중 몇명이 믿고 있나 반복문을 통해 체크함
int count_truth(int index){
    int count = 0;
    for(int i = 0; i < v[index].size(); i++){
        int tmp = v[index][i];
        if(truth[tmp])
            count++;
    }
    return count;
}
