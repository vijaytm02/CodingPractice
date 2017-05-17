#include <bits/stdc++.h>
using namespace std;
long long arr[510][510];
int k;
long long call(int l,int r){
	if(l>=r)
		return 0;
	if(l+1==r){
		return l+l+k+k;
	}
	if(arr[l][r]!=-1)
		return arr[l][r];
	long long ans=0x3f3f3f3f;
	for(int i=l;i<=r;i++)
		ans=min(ans,(r-l+1)*(i+k)+call(l,i-1)+call(i+1,r));
	return arr[l][r]=ans;
}
int main() {
	int t,n,i=0;
	cin>>t;
	while(t--){
		cout<<"Case "<<(++i)<<": ";
		memset(arr,-1,sizeof arr);
		cin>>n>>k;
		cout<<(call(1,n))<<endl;
	}
	return 0;
}
