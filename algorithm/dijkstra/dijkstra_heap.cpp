#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int num = 6;
int inf = 1e7;

vector <pair<int, int> > a[7]; // 간선정보
int d[7]; // 최소 거리
void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int current = pq.top().first;
        //짧은 것이 먼저 오도록 음수화
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < a[current].size(); i++){
            //선택된 노드의 인접노드
            int next = a[current][i].first;
            //선택된 노드를 거쳐서 인접노드로 가는 비용
            int nextDistance = distance + a[current][i].second;
            //기존의 최소 비용보다 더 저렴하다면 교체
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                //priority_queue는 기본적으로 큰값이 위로 가기때문에 저 작은 비용이 위쪽으로 가야해서 음수화함
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}

int main(void){
    //연결되지 않으면 비용은 무한대
    for(int i = 1; i <= num; i++)
        d[i] = inf;
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));

    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));

    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,3));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));

    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));

    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1));
    a[5].push_back(make_pair(6,2));

    a[3].push_back(make_pair(3,5));
    a[3].push_back(make_pair(5,2));

    dijkstra(1);

    for(int i = 1; i <= num; i++)
        printf("%d ",d[i]);
}

//이 경우 인접리스트 방식을 활용하기 때문에 시간복잡도 O(N * logN)