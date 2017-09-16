#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
struct edge{
    int src,dest,weight;
}typedef edge;
class Graph{
    int V;
    list<int>* adj;
    list<pair<int,int>>* adjw;
    vector<pair<int,int>> subset;      //parent,rank for Union,Find with path compression
    vector<edge> edgeList; 
    public:
    Graph(int v){
        V=v;
        adj=new list<int>[V];
        adjw=new list<pair<int,int>>[V];
        subset.resize(V);
        for(int i=0;i<V;i++){
            subset[i].first=i;
            subset[i].second=0;
        }
    }
    
    //Union Find
    int _find(int i){
        if(subset[i].first!=i)
            return _find(subset[i].first);
        return i;
    }
    void _union(int x,int y){
        int xx=_find(x);
        int yy=_find(y);
        if(subset[xx].second < subset[yy].second)
            subset[xx].first=yy;
        else if(subset[xx].second > subset[yy].second)
            subset[yy].first=xx;
        else{
            subset[xx].first=yy;
            subset[yy].second++;
        }
    }
    
    
    void _addEdge(int u,int v,int w){          //For Kruskals
        edge e;
        e.src=u;
        e.dest=v;
        e.weight=w;
        edgeList.push_back(e);
    }
    void addEdge(int u,int v){                  //Normal Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void addEdge(int u,int v,int w){            //For Prims
        adjw[u].push_back(make_pair(v,w));
        adjw[v].push_back(make_pair(u,w));
    }
    int prim(){
        priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> parent(V,-1);
        vector<int> key(V,INF);
        vector<bool> visited(V,false);
        pq.push(make_pair(0,0));
        while(!pq.empty()){
            pair<int,int> tp=pq.top();
            pq.pop();
            int v=tp.second;
            visited[v]=true;
            for(auto it=adjw[v].begin();it!=adjw[v].end();it++){
                int u=it->first;
                int weight=it->second;
                if(!visited[u] && key[u]>weight){
                    parent[u]=v;
                    key[u]=weight;
                    pq.push(make_pair(weight,u));
                }
            }
        }
        int sum=0;
        for(int i=1;i<V;i++){
            sum+=key[i];
        }
        return sum;
    }
    int kruskals(){
        sort(edgeList.begin(),edgeList.end(),[](const edge& a,const edge& b){
            return a.weight<b.weight;
        });
        int e=0;
        int i=0;
        vector<bool> taken(edgeList.size(),false);
        while(e!=V-1 && i<edgeList.size()){
            edge ed=edgeList[i];
            int s=ed.src;
            int d=ed.dest;
            int w=ed.weight;
            int x=_find(s);
            int y=_find(d);
            if(x!=y){
                e++;
                taken[i]=true;
                _union(x,y);
            }
            i++;
        }
        int sum=0;
        for(int i=0;i<edgeList.size();i++) if(taken[i])
            sum+=edgeList[i].weight;
        return sum;
    }
    void Bfs(int v){
        vector<bool> visited(V,false);
        visited[v]=true;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(auto it=adj[u].begin();it!=adj[u].end();it++){
                if(!visited[*it]){
                    visited[*it]=true;
                    q.push(*it);
                }
            }
        }
        cout<<endl;
    }
    bool isCyclic(){
        vector<bool> part(V,false);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
                if(Cycle(i,part,visited))
                    return true;
        }
        return false;
    }
    bool Cycle(int i,vector<bool>& part,vector<bool>& visited){
        part[i]=true;
        visited[i]=true;
        for(auto it=adj[i].begin();it!=adj[i].end();it++){
            int v=*it;
            if(part[v])
                 return true;
            if(!visited[v])
                if(Cycle(v,part,visited))
                    return true;
        }
        part[i]=false;
        return false;
        return 0;
    }
    int AP_Util(int u,bool visited[],bool ap[],int parent[],int disc[],int low[]){
        static int time=0;
        time++;
        visited[u]=true;
        disc[u]=time;
        low[u]=time;
        int children=0;
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            int v=*it;
            if(!visited[v]){
                children++;
                parent[v]=u;
                AP_Util(v,visited,ap,parent,disc,low);
                low[u]=min(low[u],low[v]);
                if(parent[u]==-1 && children>1)
                    ap[u]=true;
                else if(parent[u]!=-1 && low[v]>=disc[u])
                    ap[u]=true;
            }
            else if(v!=parent[u])
                low[u]=min(low[u],disc[v]);
        }
        return 0;
    }
    int AP(){
        bool visited[V];
        bool ap[V];
        int parent[V];
        int disc[V];
        int low[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            parent[i]=-1;
            ap[i]=false;
        }
        for(int i=0;i<V;i++)
            if(!visited[i])
                AP_Util(i,visited,ap,parent,disc,low);
        for(int i=0;i<V;i++)
            if(ap[i])
                cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    int Dijkstra(int src){
        vector<int> min_distance(V,INF);
        min_distance[src]=0;
        set<pair<int,int>> active;
        active.insert({0,src});
        while(!active.empty()){
            pair<int,int> p=*active.begin();
            int u=p.second;
            int d=p.first;
            active.erase(active.begin());
            for(auto it=adjw[u].begin();it!=adjw[u].end();it++){
                if(min_distance[it->first]>d+it->second){
                    active.erase({min_distance[it->first],it->first});
                    min_distance[it->first]=d+it->second;
                    active.insert({min_distance[it->first],it->first});
                }
            }
        }
        for(int i=0;i<V;i++)
            cout<<"Vertex : "<<i<<"   Shortest Distance from : "<<src<<" = "<<min_distance[i]<<endl;
        return 0;
    }
};

int main(){
    /*int V = 9;
    Graph g(V);
 
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    cout<<g.prim();        ans=37
    */
    /*Graph g(4);
    g._addEdge(0,1,10);
    g._addEdge(1,3,15);
    g._addEdge(2,3,4);
    g._addEdge(0,2,6);
    g._addEdge(0,3,5);
    cout<<g.kruskals()<<endl;       ans=19
    Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       
    */
    
    /*Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";*/
    
    /*cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);                                              ans=0 3
    g1.AP();
 
    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);                                              ans=1 2
    g2.AP();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);                                              ans=1
    g3.AP();
    
    */
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.Dijkstra(0);
    return 0;
}
