//articuation point and graph
#include<bits/stdc++.h>
using namespace std;
class Graph{
  int V;
  list<int> * adj;
  public:
  Graph(int);
  int addEdge(int u,int v);
  int DFS_Util(int,bool[],int[],int[],int[],bool[]);
  int DFS();
  int BFS(int);
};

Graph::Graph(int n){
    V=n;
    adj= new list<int>[V];
}
int Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    return 1;
}
int Graph::DFS_Util(int u,bool visit[],int disc[],int low[],int parent[],bool ap[]){
    visit[u]=true;
    static int tm = 0;
    disc[u]=low[u]=++tm;
    list<int>::iterator it=adj[u].begin();
    int child=0;
    for(;it!=adj[u].end();it++){
        int v=*it;
        if(!visit[v]){
            child++;
            DFS_Util(v,visit,disc,low,parent,ap);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && child>1)
                ap[u]=true;
            else if(parent[u]!=-1 && low[v]>=disc[u])
                ap[u]=true;
        }
        else{
            if(v!=parent[u])
                low[u]=min(low[u],disc[v]);
        }
    }
    return 1;
}
int Graph::DFS(){
    bool* visit=new bool[V];
    bool* ap=new bool[V];
    int* disc=new int[V];
    int* low=new int[V];
    int* parent=new int[V];
    for(int i=0;i<V;i++){
        parent[i]=-1;
        visit[i]=ap[i]=false;
        disc[i]=low[i]=0;
    }
    for(int i=0;i<V;i++)
        if(!visit[i])
            DFS_Util(i,visit,disc,low,parent,ap);
    cout<<"\nArticulation Points: ";
    for(int i=0;i<V;i++){
        if(ap[i])
            cout<<i<<" ";
    }
    return 1;
}
int Graph::BFS(int s){
    bool* visit=new bool[V];
    memset(visit,false,sizeof visit);
    visit[s]=true;
    list<int> q;
    q.push_back(s);
    while(!q.empty()){
        int node=q.front();
        q.pop_front();
        cout<<node<<" ";
        list<int>::iterator it=adj[node].begin();
        for(;it!=adj[node].end();it++)
            if(!visit[*it]){
                q.push_back(*it);
                visit[*it]=true;
            }    
    }
    return 1;
}

int main(){
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.DFS();
}
