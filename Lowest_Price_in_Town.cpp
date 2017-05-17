#include <bits/stdc++.h>
using namespace std;
float price[101];

int main() {
	string str;
	int M,N;
	float UP,P;
	char* st;
	int test=0;
	while(1){
		
		memset(price,-1,sizeof price);
		getline(cin,str);
		if(str.length()==0)
			break;
		cout<<"Case "<<(++test)<<":"<<endl;
		sscanf(str.c_str(),"%f %d",&UP,&M);
		int max1=0;
		for(int i=0;i<M;i++){
			getline(cin,str);
			sscanf(str.c_str(),"%d %f",&N,&P);
			price[N]=P;
			max1=max(max1,N);
		}
		getline(cin,str);
		vector<int> val;
		char* arr=const_cast<char*>(str.c_str());
		st=strtok(arr," ");
		while(st!=NULL){
			val.push_back(atoi(st));
			st=strtok(NULL," ");
		}
		int k=max1;
		price[0]=0;
		price[1]=UP;
		float ans;
		for(int i=2;i<=k;i++){
			ans=0x3f3f3f3f;
			for(int j=0;j<=i/2;j++){
				if(price[j]!=-1 && price[i-j]!=-1)
					ans=min(ans,price[j]+price[i-j]);
			}
			price[i]=ans;
		}
		for(int i=k;i>=1;i--){
			int j;
			for(j=i-1;j>=1 && price[j]>price[i];j--){
				price[j]=price[i];
			}
			i=j+1;
		}
		for(int i=0;i<val.size();i++){
			printf("Buy %d for $%0.2f\n",val[i],price[val[i]]);
		}
	}
	return 0;
}
