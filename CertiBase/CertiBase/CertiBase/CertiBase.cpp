#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int max_longlong = 9223372036854775807;

int N;
int M;
ll Answer;
int Parent[1001];
ll PSum[1001];

vector<int> Input;

void init()
{
    for (int i = 0; i < 1000; i++)
    {
        Parent[i] = i;
        PSum[i] = max_longlong;
    }
    Answer = 0;
    Input.clear();
}

int findP(int x)
{
    if (Parent[x] == x) return x;
    
    int p = findP(Parent[x]);
    return Parent[x] = p;
}

void UnionP(int x, int y, int cost)
{
    int xx = findP(x);
    int yy = findP(y);

    if (xx == yy)
    {
        if (PSum[x] > PSum[y])
        {
            PSum[x] = cost;
            Parent[x] = yy;
        }
        else {
            PSum[y] = cost;
            Parent[y] = xx;
        }
        return;
    }

    if (PSum[y] >= cost)
    {
        PSum[y] = cost;
        Parent[yy] = xx;
    }

    return;
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    init();

    int a, b, c;
    for (int m = 0; m < M; m++)
    {
        scanf("%d %d %d", &a, &b, &c);

        if (a == b)
            continue;
        UnionP(a, b, c);
    }

    for (int i = 2; i <= N; i++)
    {
        Answer += PSum[i];
    }

    printf("%lld", Answer);

    return 0;
}
