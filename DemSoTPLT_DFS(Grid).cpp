#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
int a[1001][1001];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int i, int j)
{
	a[i][j] = 0;
	for(int k = 0; k < 8; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1)
		{
			dfs(i1, j1);
		}
	}	
}
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 1)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	int test; cin >> test;
	while(test--)
	{
		inp();
		//ConnectedComponent();
	}
	return 0;
}

