#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int n, m;

void init()
{
	for (int i = 0; i <= n; i++)
	{
		parent.push_back(i);
	}
}

int findU(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = findU(parent[x]);
}

void UnionU(int x, int y)
{
	int xx = findU(x);
	int yy = findU(y);
	parent[yy] = xx;
}

int main()
{
	scanf("%d %d", &n, &m);
	init();
	int q, a, b;
	for (int t = 0; t < m; t++) {
		scanf("%d %d %d", &q, &a, &b);

		if (q == 0) {
			UnionU(a, b);
		}
		else {
			if (findU(a) == findU(b))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
}
