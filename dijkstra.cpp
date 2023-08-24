#include <bits/stdc++.h>
using namespace std;

#define w(t)   \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define int long long int
#define ld long double
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define pi 2 * acos(0.0)
#define endl '\n'
#define case cout << "Case " << cs++ << ": "
#define pow(a, b) (int)(pow(a, b) + eps)
#define pb push_back
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define bb begin()
#define ee end()
#define ff first
#define ss second
#define endl '\n'
#define mod 1000000007
#define INF LLONG_MAX
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
/****************** PRINT ALL SUBSET OF GIVEN SUM *******************/
const int N = 1000005;
vector<pair<int, int>> adj[N];
vector<int> dist;
vector<bool> visited;
vector<int> par;
void delet(int n)
{
    for (int i = 0; i <= n; i++)
        adj[i].clear();
}

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int tempDist = pq.top().first;
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (auto it : adj[cur])
        {
            int to = it.first, w = it.second;
            if (dist[cur] + w < dist[to])
            {
                par[to] = cur;
                dist[to] = dist[cur] + w;
                pq.push({dist[to], to});
            }
        }
    }
}
vector<int> BackTrack(int x)
{
    vector<int> ret;
    while (x != -1)
    {
        ret.pb(x);
        x = par[x];
    }
    reverse(ret.bb, ret.ee);
    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    delet(n);
    dist.assign(n + 1, INF);
    visited.assign(n + 1, false);
    par.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijkstra(1);
    // cout << dist[n] << endl;
    if (dist[n] == INF)
        cout << -1 << endl;
    else
    {
        vector<int> track = BackTrack(n);
        for (auto it : track)
            cout << it << " ";
    }
}
int32_t main()
{

    fastio;
    // w(t)
    solve();
}
