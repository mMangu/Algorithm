#include <cstdio>
#include <algorithm>

using namespace std;

int H[606];
int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf(" %d", &H[i]);
    sort(H, H + N);
    int a, b, c, d, tmp,minimum = 1000000009;
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                b = H[i];
                c = H[j];
                d = H[k];
                tmp = b + c - d;
                int end = i-1, begin = 0;
                while (1)
                {   
                    if(begin == end){
                        a = H[end];
                        break;
                    }
                    if (H[(begin + end) / 2] > tmp)
                        end = (begin + end) / 2;
                    else if (H[(begin + end) / 2] == tmp)
                        {
                            a = tmp;
                            break;
                        }
                    else
                        begin = (end + begin) / 2;
                    if(begin == end -1)
                    {
                        if(abs(tmp - H[begin]) < abs(tmp - H[end]))
                            a = H[begin];
                        else
                            a = H[end];
                        break;
                    }
                }
                minimum = min(minimum,abs(a+d-(b+c)));
            }
        }
    }
    printf("%d",minimum);
    return 0;
}

// 몰라서 준표형한테 물어봄
// (a+d) - (b+c) 의 절대값이 키 차이인건 확실하니까 b c d고정시키고 a를 이동시킴
// a 구하는건 이진탐색 
// -> 시간복잡도 O(N^3*lonN)
//근데 복잡도가 N^3 이상이니까 정해는 아님

// 플로우
// 4개를 택해야겠는데 하나가 그럼 N^4이네?
// 몇개를 고정시켜야겠다
// 3개를 고정시키고 나머지를 이동해보자
