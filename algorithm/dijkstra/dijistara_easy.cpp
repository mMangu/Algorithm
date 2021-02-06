#include <cstdio>

int num = 6;
int inf = 1e7;

//그래프 초기화
int a[6][6] = {
    // 1 -> 2 길이 = 2 , 1 -> 3 길이 = 5, inf 는 한방에 못가는 노드 이런느낌
    {0 , 2 , 5, 1, inf, inf}, 
    {2, 0, 3, 2, inf, inf},
    {5 , 3 , 0 , 3 , 1 ,5},
    {1, 2, 3, 0, 1, inf},
    {inf, inf, 1, 1, 0, 2},
    {inf, inf, 5, inf, 2, 0},
};
bool v[6]; //방문한 노드
int d[6]; // 최단 거리

//가장 최소 거리를 가지는 정점 반환
int getSmallIndex(){
    int min = inf;
    int index = 0;
    for(int i = 0; i < num; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}
 //다익스트라 수행
 void dijkstra(int start){
     for(int i = 0; i < num; i++){
         d[i] = a[start][i];
     }
     v[start] = true;
     for(int i = 0; i < num - 2; i++){ // num-2 는 a[0]의 size
         int current = getSmallIndex();
         v[current] = true;
         for(int j = 0; j < 6; j++){
             if(!v[j]){
                 if(d[current] + a[current][j] < d[j])
                    d[j] = d[current] + a[current][j];
             }
         }
     }
 }
 int main(void){
     dijkstra(0);
     for(int i = 0; i < num; i++)
        printf("%d ",d[i]);
 }

 //2차원 배열로 구현시 정점의 개수가 많은데 간선이 적을때 비효율적 또한 시간복잡도도 O(N^2)