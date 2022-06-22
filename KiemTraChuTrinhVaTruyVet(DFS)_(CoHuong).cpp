#include <bits/stdc++.h>
using namespace std;
int n, m, st, en;
vector <int> adj[100001];
int color[100001];
int parent[100001];
void inp()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
bool DFS(int u)
{
	color[u] = 1;
	for(int v : adj[u])
	{
		if(color[v] == 0)
		{
			parent[v] = u;
			if(DFS(v))
				return true;
		}
		else if(color[v] == 1)
		{
			st = v, en = u;
			return true;
		}
	}
	color[u] = 2;
	return false;
}
int main()
{
	inp();
	bool logic = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!color[i]){
			if(DFS(i) == 1){
				stack <int> cycle;
				cycle.push(st);
				while(st != en){
					cycle.push(en);
					en = parent[en];
				}
				cycle.push(st);
				cout << cycle.size() << endl;
				while(!cycle.empty()){
					cout << cycle.top() << " "; cycle.pop();
				}
				logic = 1;
				break;
			}
		}
		
	}
	if(logic == 0) cout << "IMPOSSIBLE";
	return 0;
}
//10 20
//1 7
//2 8
//10 5
//4 8
//7 10
//6 4
//9 10
//7 2
//6 3
//4 7
//9 3
//2 5
//4 3
//8 9
//7 1
//5 10
//7 6
//8 1
//8 2
//6 7
