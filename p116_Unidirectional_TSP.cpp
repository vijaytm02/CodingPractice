#include <bits/stdc++.h>
using namespace std;
int m,n;
int start;
vector<vector<int>> weight;
vector<vector<int>> cost;

int call(int p,int q){
	//cout<<"("<<p<<","<<q<<")"<<endl;
	if(q==n)
		return 0;
	if(cost[p][q]!=-1)
		return cost[p][q];
	return cost[p][q]=weight[p][q]+min({call((p-1+m)%m,q+1),call(p,q+1),call((p+1)%m,q+1)});
}
int print(){
	int r=start,c=0,f,s,t;
	cout<<(r+1);
	while(c!=n-1){
		int arr[3]={(r-1+m)%m,r,(r+1)%m};
		sort(arr,arr+3);
		f=arr[0];
		s=arr[1];
		t=arr[2];
		
		if(cost[f][c+1] <= cost[s][c+1] && cost[f][c+1] <= cost[t][c+1]){
			cout<<" "<<(f+1);
			r=f;
			c++;
			continue;
		}
		if(cost[s][c+1] <= cost[t][c+1] && cost[s][c+1] < cost[f][c+1]){
			cout<<" "<<(s+1);
			r=s;
			c++;
			continue;
		}
		if(cost[t][c+1] < cost[s][c+1] && cost[t][c+1] < cost[f][c+1]){
			cout<<" "<<(t+1);
			r=t;
			c++;
			continue;
		}
	}
	cout<<endl;
}

int main() {
	string str;
	while(scanf("%d %d",&m,&n)==2){
		weight.assign(m,vector<int>(n,0));
		cost.assign(m,vector<int>(n,-1));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>weight[i][j];
			}
		}
		int ans=0x7fffffff;
		int temp;
		for(int i=0;i<m;i++){
			temp=call(i,0);
			if(temp<ans){
				ans=temp;
				start=i;
			}
		}
		print();
		cout<<ans<<endl;
		/*for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<cost[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	return 0;
}
