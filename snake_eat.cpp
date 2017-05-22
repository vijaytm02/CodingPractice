#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,N,Q,t,count=0;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		vector<int> v1(N);
		vector<int> query(Q);
		int i=0;
		while(i<N){
			cin>>t;
			v1[i]=t;
			i++;
		}
		i=0;
		while(i<Q){
			cin>>t;
			query[i]=t;
			i++;
		}
		sort(v1.begin(),v1.end(),greater<int>());
		
		int minth=*min(query.begin(),query.end());
		vector<int> ns;
		int j=0;
		while(v1[j]>=minth && j<v1.size()){j++;ns.push_back(v1[j]);}
		int k=v1.size()-1;
		int cs;
		while(j<k){
			cs=v1[j];
			if(k-(minth-cs)+1<=j){
				break;
			}
		    k=k-(minth-cs);
		    ns.push_back(minth);
			j++;
		}
		
		i=0;
		while(i<Q){
			count=0;
			int j=0;
			int th=query[i];
			while(v1[j]>=th && j<v1.size()){count++;j++;}
			if(j==v1.size()){
				cout<<j<<endl;
				i++;
				continue;
			}
			//cout<<count<<" "<<j<<endl;
			int k=v1.size()-1;
			int cs;
			while(j<k){
				cs=v1[j];
				if(k-(th-cs)+1<=j){
					break;
				}
				k=k-(th-cs);
				count++;
				j++;
				//cout<<"K="<<k<<" count="<<count<<endl;
			}
			cout<<count<<endl;
			i++;
		}
	}
	return 0;
}
