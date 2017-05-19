#include <bits/stdc++.h>
using namespace std;
double price[205];

int main() {
	string str;
	int M,N;
	float UP,P;
	int test=0;
	while(1){
		getline(cin,str);
		if(str.length()==0)
			break;
		cout<<"Case "<<(++test)<<":"<<endl;
		sscanf(str.c_str(),"%f %d",&UP,&M);
		price[0]=0;
        for(int i = 1; i < 205; i++)    price[i] = 0xfffffff;
        for(int i = 1; i < 205; i++) {
            price[i] = min(price[i], price[i-1]+UP);
        }
		for(int i=0;i<M;i++){
			getline(cin,str);
			sscanf(str.c_str(),"%d %f",&N,&P);
			for(int j=N;j<= 200;j++)
				price[j]=min(price[j],price[j-N]+P);
		}
		for(int j = 200; j >= 0; j--)
            price[j] = min(price[j], price[j+1]);;
		getline(cin,str);
		stringstream ss(str);
		int k;
		while(ss>>k)
			printf("Buy %d for $%0.2f\n",k,price[k]);
	}
	return 0;
}
