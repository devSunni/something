#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll max_longlong = 9223372036854775807;

struct info {
    int a;
    int b;
    int c;
};
int N;
int M;


ll Answer;
int Parent[1001];
ll PSum[1001];

vector<info> Input;

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

ll UnionP(int x, int y, ll cost)
{
    int xx = findP(x);
    int yy = findP(y);

    if (xx == yy)
    {
        return 0;
    }

    PSum[y] = cost;
    Parent[yy] = xx;

    return cost;
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

        Input.push_back({ a, b, c });
    }

    sort(Input.begin(), Input.end(), [](info a, info b) {
        return a.c < b.c;
        });

    for (int m = 0; m < M; m++)
    {
        if (Input[m].a != Input[m].b)
        {
            Answer += UnionP(Input[m].a, Input[m].b, Input[m].c);
        }
    }

    printf("%lld", Answer);

    return 0;
}
