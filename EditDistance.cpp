#include <bits/stdc++.h>
using namespace std;

int Edit(string str1,string str2){
	int len1=str1.length();
	int len2=str2.length();
	int arr[len1+1][len2+1];
	for(int i=0;i<=len1;i++){
		for(int j=0;j<=len2;j++){
			if(i==0 && j==0)
				arr[i][j]=0;
			else if(i==0)
				arr[i][j]=j;
			else if(j==0)
				arr[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				arr[i][j]=arr[i-1][j-1];
			else
				arr[i][j]=min({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]})+1;
		}
	}
	return arr[len1][len2];
}

int main() {
	int T;
	string str1,str2;
	getline(cin,str1);
	T=atoi(str1.c_str());
	while(T--){
		getline(cin,str1);
		getline(cin,str2);
		cout<<Edit(str1,str2)<<endl;
	}
	return 0;
}
