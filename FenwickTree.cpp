#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class FenwickTree{
	vi Ft;
	int n;
public:
	FenwickTree(vi & p){
		n=p.size();
		Ft.assign(n+1,0);
		for(int i=0;i<p.size();i++){
			UpDate(i,p[i]);
		}
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
	vector<int> arr;
	for(int i=0;i<10;i++){
		arr.push_back(2*i);
	}
	FenwickTree tr(arr);
	cout<<tr.GetSum(5);
	return 0;
}
