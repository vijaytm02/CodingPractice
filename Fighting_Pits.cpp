#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<long long> strength;
vector< vector<int> >teams;
class FenwickTree{

public:
	vi Ft;
	int n;
	FenwickTree(int b){
		vi& p=teams[b];
		n=p.size();
		Ft.assign(n+1,0);
		for(int i=0;i<p.size();i++){
			UpDate(i,p[i],b);
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
	int UpDate(int ind,int val,int b){
			if(ind>=n){
		    n=n+1000;;
			Ft.assign(n+1,0);
			for(int i=0;i<teams[b].size();i++)
				UpDate(i,teams[b][i],b);
            return 1;
        }
		ind=ind+1;
		while(ind<=n){
			Ft[ind]+=val;
			ind+= ind & (-ind);
		}
		return 1;
	}
	int print(){
        for(int i=1;i<=n;i++){
            cout<<Ft[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
};
vector<FenwickTree> fen;

int match(int b,int c,int sb,int sc){
    vector<int>& x=teams[b];
    vector<int>& y=teams[c];
    int i=x.size()-1,j=y.size()-1,turn=1;
    long long t=0;
        int mp;
    while(i>=0 && j>=0){
        if(turn==1){
            if(sb>=sc)
                return b;
            t=0;
            mp=j-x[i];
            if(mp<0)
                return b;
            t=fen[c].GetSum(j)-fen[c].GetSum(mp);
            sc-=t;
            j=mp;
            turn=2;        
        }
        else{
            if(sc>=sb)
                return c;
            t=0;
            mp=i-y[j];
            if(mp<0)
                return c;
            t=fen[b].GetSum(i)-fen[b].GetSum(mp);
            sb-=t;
            i=mp;
            turn=1;
        }
    }
    if(i<0)
        return c;
    return b;
}

int main() {
    int n,k,q,s,t;
    scanf("%d %d %d",&n,&k,&q);
    strength.assign(k+1,0);
    teams.resize(k+1);
    for(int i=0;i<n;i++){
        scanf("%d %d",&s,&t);
        teams[t].push_back(s);
        strength[t]+=s;
    }
    vector<int> ab(1);
    ab[0]=1;
    fen.push_back(1);
    for(int i=1;i<=k;i++){
        sort(teams[i].begin(),teams[i].end());
        fen.push_back(FenwickTree(i));
    }
    
    int a,b,c;
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            teams[c].push_back(b);
            strength[c]+=b;
            fen[c].UpDate(teams[c].size()-1,b,c);		   
        }
        else{      
            int v=match(b,c,strength[b],strength[c]);
            printf("%d\n",v);
        }
    }
    return 0;
}
