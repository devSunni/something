#include <iostream>

using namespace std;

const int max_int = 214783647;
int N;
int M;
int dist[501][501];


void init()
{
    for (int i = 1; i < 501; i++) {
        for (int j = 1; j < 501; j++)
        {
            dist[i][j] = max_int;
        }

    }
}
int main()
{

    init();
    scanf("%d %d", &N, &M);

    int a, b;

    for (int m = 0; m < M; m++)
    {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++)
            {
                if ((i != k) && (i != j) && (j != k))
                {
                    if (dist[i][k] > dist[i][j] + dist[j][k])
                        dist[i][k] = dist[i][j] + dist[j][k];
                }                        
            }
        }
    }

    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i != j) {
                if ((dist[i][j] != max_int) || (dist[j][i] != max_int))
                {
                    cnt++;
                }
            }
            if ((N - 1) > (N - j + cnt))
                break;

        }

        if (cnt == N - 1)
            ans++;

        cnt = 0;
    }

    printf("%d", ans);

    return 0;
}
