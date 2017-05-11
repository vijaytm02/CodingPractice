#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class FenwickTree{
	vi Ft;
	int n;
public:
	FenwickTree(int len){
		n=len;
		Ft.assign(n+1,0);
	}
	int GetSum(int ind){
		ind =ind+1;
		int sum=0;
		while(ind>0){
			sum+=Ft[ind];
			ind-=ind & (-ind);
		}
		return sum;
	}
	int UpDate(int ind,int val){
		ind=ind+1;
		while(ind<=n){
			Ft[ind]+=val;
			ind+= ind & (-ind);
		}
		return 1;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,K,t;
	cin>>N>>K;
	vector<FenwickTree> arr(K+1,FenwickTree(100100));
	vector<int> nums(N);
	for(int i=0;i<N;i++){
		cin>>t;
		nums[i]=t+1;
	}
	for(int i=0;i<N;i++){
		for(int j=K;j>=1;j--){
			if(j==1)
				arr[j].UpDate(nums[i],1);
			else{
				int sum=arr[j-1].GetSum(nums[i]-1);
				arr[j].UpDate(nums[i],sum);
			}
		}
	}
	cout<<arr[K].GetSum(100010);
	return 0;
}
