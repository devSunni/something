﻿#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MaxNode = 100001;

struct info {
    int a;
    int b;
};

int N;
int M;

int Parent[MaxNode];
set<int> pp[MaxNode];

void init() {
    for (int i = 0; i < MaxNode; i++) {
        Parent[i] = i;
        pp[i].clear();
    }
}

int findP(int x) {
    pp[x].insert(Parent[x]);
    if (Parent[x] == x) return x;
    int p = findP(Parent[x]);
    return Parent[x] = p;
}

void unionP(int x, int y) {
    int xx = findP(x);
    int yy = findP(y);
    if (xx == yy) return;
    Parent[yy] = xx;
    pp[y].insert(x);
    pp[y].insert(pp[x].begin(), pp[x].end());
    return;
}

int main()
{
    init();
    int a, b;

    scanf("%d", &N);

    for (int n = 0; n < N - 1; n++) {
        scanf("%d %d", &a, &b);
        if (a < b) {
            unionP(a, b);
        }
        else
        {
            unionP(b, a);
        }
        
    }

    vector<int> Answer;
    scanf("%d", &M);
    for(int m = 0; m < M; m++) {
        scanf("%d %d", &a, &b);


        Answer.clear();
        Answer.resize(MaxNode);
        set_intersection(pp[a].begin(), pp[a].end(), pp[b].begin(), pp[b].end(), Answer.begin());

        int ans = upper_bound(Answer.rbegin(), Answer.rend(), 0) - Answer.rbegin();
        
        ans = Answer[MaxNode - ans - 1];
        printf("%d\n", ans);
    }

    return 0;
}
