#include <cstdio>
char input[500005];

int main(void)
{
    int cnt = 0, blue_cnt = 0, red_cnt = 0;
    int N;
    scanf("%d", &N);
    scanf("%s", input);
    if(input[0] == 'B')
        blue_cnt++;
    else
        red_cnt++;
    for (int i = 0; i < N - 1; i++)
    {
        if (input[i] == 'B' && input[i + 1] == 'R')
            red_cnt++;
        if (input[i] == 'R' && input[i + 1] == 'B')
            blue_cnt++;
    }
    if(blue_cnt >= red_cnt)
        printf("%d",red_cnt+1);
    else
        printf("%d",blue_cnt+1);
    return 0;
}