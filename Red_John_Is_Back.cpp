#include <bits/stdc++.h>
using namespace std;

int count(int n){
	bool prime[n+1];
	memset(prime,true,sizeof prime);
	for(int p=2;p*p<=n;p++)
		if(prime[p])
			for(int i=p*2;i<=n;i+=p)
				prime[i] = false;
	int cnt=0;
	for(int i=2;i<=n;i++)
		if(prime[i])
			cnt++;
	return cnt;
}

long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main() {
	int t,n;
	long long sum=0;
	cin>>t;
	while(t--){
		cin>>n;
		sum=1;
		int level=n/4;
		for(int i=1;i<=level;i++){
			sum+=C(n-4*i+i,i);
		}
		cout<<count(sum)<<endl;
	}
	return 0;
}
