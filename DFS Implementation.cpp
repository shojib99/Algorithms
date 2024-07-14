#include <bits/stdc++.h>
using namespace std;
void int_code()
{

}
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    //part 1:actions just after entering noden u
    visited[u] = true;
    cout << "Visiting node: " << u << endl;

    for(int v: adj[u])
    {
        //part 2:actions before entering a new neighbor
        if(visited[v] == true) continue;
        dfs(v);
        //part 3:actions after exiting a neighbor
    }
    //part 4:actions before exiting node u
}
int main()
{
    int_code();

    int n,m;
    cin >> n >> m;

    for(int i=0;i<=m;i++)
    {
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);



    return 0;
}
