#include <bits/stdc++.h>
using namespace std;
int n, a[50][50], r_a[50][50];
bool used[50] = {0};
stack <int> st;
void inp()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			r_a[j][i] = a[i][j];
		}
	}
}
void DFS1(int u)
{
	used[u] = 1;
	for(int v = 1; v <= n; v++)
	{
		if(!used[v] && a[u][v])
			DFS1(v);
	}
	st.push(u);
}
void DFS2(int u)
{
	used[u] = 1;
	for(int v = 1; v <= n; v++)
	{
		if(!used[v] && r_a[u][v])
			DFS2(v);
	}
}
void SCC()
{
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
			DFS1(i);
	}
	memset(used, 0, sizeof(used));
	int cnt = 0;
	while(!st.empty())
	{
		int v = st.top(); st.pop();
		if(!used[v])
		{
			cnt++;
			DFS2(v);
		}
	}
	if(cnt == 1) cout << "strongly connected";
	else cout << "not strongly connected";
}
int main()
{
	inp();
	SCC();
	return 0;
}
