#include <bits/stdc++.h>
using namespace std;
int n, m, x1, y1, x2, y2;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int a[1001][1001];
bool dfs(int i, int j)
{
	cout << i << " " << j << endl;
	if(i == x2 && j == y2)
		return true;
	a[i][j] = 0;
	for(int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1)
			if(dfs(i1, j1)) return true;
	}
	return false;
	
}
int main()
{
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	if(dfs(x1, y1))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
