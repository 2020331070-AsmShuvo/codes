#include<bits/stdc++.h>
using namespace std;
#define     INF     3000
struct edge
{
    int src, dest, wt;
};

int V,E;

void Bellman(vector <edge> &Edges)
{
    int parent[V+5];
    vector<int> value(V+5,INF);
    parent[1]=-1;
    value[1]=0;
    bool updated;
    for(int i=0; i<V-1; i++)
    {
        updated=false;
        for(int j=0; j<E; j++)
        {
            int u=Edges[j].src;
            int v=Edges[j].dest;
            int w=Edges[j].wt;
            if(value[u]!=INF && value[u]+w<value[v])
            {
                updated=true;
                value[v]=value[u]+w;
                parent[v]=u;
            }
        }
        if(!updated) break;
    }
    for(int j=0; j<E && updated; j++)
    {
         int u=Edges[j].src;
            int v=Edges[j].dest;
            int w=Edges[j].wt;
            if(value[u]!=INF && value[u]+w<value[v])
            {
                cout<<"Negative cycle found"<<endl;
                return;
            }
    }
    for(int i=1; i<=V; i++){
        cout<<value[i]<<" ";
    }
}

int main()
{
    cin>>V>>E;
    vector <edge> edges(E);
    for(int i=0; i<E; i++)
    {
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }
    Bellman(edges);

}