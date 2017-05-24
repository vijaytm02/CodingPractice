#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list<int> * adj;
  vector<int> Indeg;
  vector<char> mapp;
  vector<string> q;
  int ind;
  int find(char ch){
  	int i;
  	for(i=0;i<V;i++){
  		if(mapp[i]==ch)
  			return i;
  		if(mapp[i]==-1)
  			break;
  	}
  	return i;
  }
  int topologicalsort_util(vector<int>& res,bool* visited){
      int flag=false;
      for(int i=0;i<V;i++){
          if(Indeg[i]==0 && visited[i]==false){
              visited[i]=true;
              for(auto it=adj[i].begin();it!=adj[i].end();it++){
                    Indeg[*it]--;
              }
              res.push_back(i);
              
              topologicalsort_util(res,visited);
              
              res.erase(res.end()-1);
              visited[i]=false;
              for(auto it=adj[i].begin();it!=adj[i].end();it++){
                    Indeg[*it]++;
              }
              flag=true;
          }
      }
      if(!flag){
      	  char* arr=new char[res.size()+1];
      	  for(int j=0;j<V;j++){
              arr[j]=mapp[res[j]];
          }
          arr[res.size()]=0;
          string str(arr);
      	  q.push_back(str);
         
      }
    return 1;
  }
  public:
  int print(){
  	sort(q.begin(),q.end());
  	for(int i=0;i<q.size();i++){
          cout<<q[i]<<endl;
  	}
  	return 1;
  }
  Graph(vector<char>& mp){
      this->V=mp.size();
      mapp.resize(V);
      for(int i=0;i<mp.size();i++){
      	mapp[i]=mp[i];
      }
      adj=new list<int>[V];
      Indeg.assign(V,0);
      ind=0;
  }
  int Add_Edge(int v,int w){
  	  int ind1=find(v);
  	  int ind2=find(w);
      adj[ind1].push_back(ind2);
      Indeg[ind2]++;
      return 1;
  }
  int All_Topplogical_Sort(){
      bool* visited=new bool[V];
      vector<int> res;
      for(int i=0;i<V;i++){
          visited[i]=false;
      }
      topologicalsort_util(res,visited);
      print();
      return 1;
  }
      
};

int main() {
	string str1,str2;
	
	getline(cin,str1);
	while(str1.length()!=0){
		vector<char> mapp;
		getline(cin,str2);
		for(int i=0;i<str1.length();i+=2){
			mapp.push_back(str1[i]);
		}
		Graph g(mapp);
		for(int i=0;i<str2.length();i+=4){
			g.Add_Edge(str2[i],str2[i+2]);
		}
		g.All_Topplogical_Sort();
		cout<<endl;
		getline(cin,str1);
	}
	
	return 0;
}
