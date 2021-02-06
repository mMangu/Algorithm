#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int home[102];
int d_A[1003];
int d_B[1003];
vector <pair<int, int> > vec[1003];

void dijkstra(int start,int d[], int V);
int main(void){
    int N,V,E; scanf("%d %d %d",&N,&V,&E);
    int A,B; scanf("%d %d", &A, &B);
    for(int i = 0; i < N; i++){
        scanf("%d",home + i);
    }
    for(int i = 0; i < E; i++){
        int a,b,c; scanf("%d %d %d",&a, &b, &c);
        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }
    dijkstra(A, d_A, V);
    dijkstra(B, d_B, V);
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum = sum + d_A[home[i]] + d_B[home[i]];
    }
    printf("%d",sum);
}

void dijkstra(int start,int d[], int V){
    for(int i = 1; i <= V; i++)
        d[i] = 200;
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < vec[current].size(); i++){
            int next = vec[current][i].first;
            int nextDistance = distance + vec[current][i].second;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}