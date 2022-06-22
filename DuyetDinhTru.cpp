#include <bits/stdc++.h>
using namespace std;
int n, a[50][50], scc1= 0, scc2, cnt = 0;
bool used[50];
void inp()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void bfs(int u)
{
    queue <int> q;
    used[u] = 1;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(!used[i] && a[v][i])
            {
                used[i] = 1;
                q.push(i);
            }
        }
    }
}
int countCC()
{
    int scc = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            scc++;
            bfs(i);
        }
    }
    return scc;
}
int main()
{
    inp();
    scc1 = countCC();
    for(int i = 1; i <= n; i++)
    {
        memset(used, 0, sizeof(used));
        used[i] = 1; // loai bo dinh 1;
        scc2 = countCC();;
        if(scc2 > scc1) cout << i << " ";
    }
    return 0;
}
