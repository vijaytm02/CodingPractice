#include <bits/stdc++.h>
using namespace std;
int m,k;
vector<int> nums;
int arr[110][10100];
int ways(int sum,int pos){
	sum=( (sum%k)+k)%k ;
	if(pos>=m){
		if(sum==0)
			return 1;
		return 0;
	}
	if(arr[sum][pos]!=-1)return arr[sum][pos];
	arr[sum][pos]=ways(sum+nums[pos],pos+1)|ways(sum-nums[pos],pos+1);
	return arr[sum][pos];
}
 
int main() {
	int n;
	cin>>n;
	while(n--){
		memset(arr,-1,sizeof arr);
		nums.clear();
		cin>>m>>k;
		nums.resize(m);
		for(int i=0;i<m;i++){
			cin>>nums[i];
		}
		int d=ways(nums[0],1);
		d == 1 ? cout<<"Divisible\n" : cout<<"Not divisible\n";
	}
	return 0;
}
