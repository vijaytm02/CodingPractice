#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		vector<int> v(m);
		for(int i=0;i<m;i++)
			cin>>v[i];
		long long sum=0;
		for(int i=v.size()-1;i>=0;i--){
			int j=i-1;
			while(j>=0 && v[j]<=v[i]){
				sum+=v[i]-v[j];
				j--;
			}
			i=j+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
