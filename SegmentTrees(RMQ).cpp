#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
void preprocess(int node,int i,int j,vector<int>& seg,vector<int>& v){
    if(i==j){
        seg[node]=i;
        return;
    }
    preprocess(2*node,i,(i+j)/2,seg,v);
    preprocess(2*node+1,(i+j)/2+1,j,seg,v);
    seg[node]=(v[seg[2*node]]<=v[seg[2*node+1]])?seg[2*node]:seg[2*node+1];
}
int query(int node,int l,int r,vector<int>& seg,vector<int>& v,int i,int j){
    if(i>r || j<l)
        return -1;
    if(i<=l && r<=j)
        return seg[node];
    int p1=query(node*2,l,(l+r)/2,seg,v,i,j);
    int p2=query(node*2+1,(l+r)/2+1,r,seg,v,i,j);
    if(p1==-1)
        return p2;
    if(p2==-1)
        return p1;
    return v[p1]<=v[p2]?p1:p2;
}
int main()
{
    int n,q,x,y;
    cin>>n;
    vector<int> v(n);
    loop(i,0,n) cin>>v[i];
    vector<int> seg((1<<((int)log2(n)+1))*2);
    preprocess(1,0,n-1,seg,v);
    cin>>q;
    loop(i,0,q){
        cin>>x;
        cin>>y;
        cout<<v[query(1,0,n-1,seg,v,x,y)]<<endl;
    }
	return 0;
}
