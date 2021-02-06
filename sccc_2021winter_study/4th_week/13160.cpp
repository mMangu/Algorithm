#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int first;
    int second;
}Arr;

Arr arr[300005];
int s[300005];
int e[300005];

bool compare(const Arr& a, const Arr& b);
int main(){
    int N; scanf("%d",&N);
    vector<int> check;
    for(int i = 0; i < N; i++){
        scanf("%d %d",&arr[i].first,&arr[i].second);
        check.push_back(arr[i].first);
        check.push_back(arr[i].second);
        s[i] = arr[i].first;
        e[i] = arr[i].second;
    }
    sort(check.begin(),check.end());
    sort(s,s+N);
    sort(e,e+N);
    int M = 0,output = -1,s_index = 0,e_index = 0,cnt = 0;
    for(int i = 0; i < 2*N; i++){
        if(check[i] == s[s_index]){
            cnt++;
            s_index++;
        }
        else if(check[i] == e[e_index]){
            cnt--;
            e_index++;
        }
        int tmp = M;
        M = max(M,cnt);
        if(M != tmp)
            output = check[i];
    }
    printf("%d\n",M);
    
    for(int i = 0; i < N; i++){
        if(arr[i].first <= output && output <= arr[i].second)
            printf("%d ",i+1);
    }
}