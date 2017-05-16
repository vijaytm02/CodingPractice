#include<cstdio>
#include<cstring>
using namespace std;
typedef long long int L;
L arr[66][66][2];


L draw(int i,int j,int x){
	if(i==1){
		if(j==0 && x==1)
			return 1;
		if(j==0 && x==0)
			return 2;
		if(j==1 && x==1)
			return 1;
		return 0;
	}
	if(i<j)
		return 0;
	if(i==j && x==0)
		return 0;
	if(arr[i][j][x] != -1)
		return arr[i][j][x];
	if(x)
		arr[i][j][x]=draw(i-1,j-1,1)+draw(i-1,j,0);
	else
		arr[i][j][x]=draw(i-1,j,0)+draw(i-1,j,1);
	return arr[i][j][x];
}

int main() {
	memset(arr,-1,sizeof arr);
	int n,s;
	while(1){
	scanf("%d %d",&n,&s);
	if(n<0 && s<0)
		break;
	printf("%lld\n",draw(n,s,1));
	}
	return 0;
}
