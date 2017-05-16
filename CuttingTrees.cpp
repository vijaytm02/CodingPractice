#include <bits/stdc++.h>
using namespace std;
int arr[60][60];
vector<int> v;
int cut(int l,int r){
	if(l+1==r)
		return 0;
	if(arr[l][r]!=-1)
		return arr[l][r];
	int ans=0x3f3f3f3f;
	for(int i=l+1;i<r;i++)
		ans=min(ans,cut(l,i)+cut(i,r)+(v[r]-v[l]));
	return arr[l][r]=ans;
}
int main() {
	int l,n;
	cin>>l;
	while(l!=0){
		cout<<"The minimum cutting is ";
		memset(arr,-1,sizeof arr);
		cin>>n;
		v.resize(n+2);
		v[0]=0;
		v[n+1]=l;
		for(int i=1;i<=n;i++)
			cin>>v[i];
		cout<<cut(0,n+1)<<"."<<endl;
		cin>>l;
	}
	return 0;
}
