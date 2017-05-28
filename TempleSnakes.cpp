#include<bits/stdc++.h>
 
#define ll                    long long int
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define eb                    emplace_back
#define ab(a)                 (a<0)?(-1*a):a
#define pc                    putchar_unlocked
#define gc                    getchar_unlocked
#define mset(a,b,c)           loop(i,0,b) a[i]=c
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define vvi                   vector<vi>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define mini                  INT_MIN
const int MX=10010896;
const int lmt=3164;
const int N=10000001;
int flag[MX>>6];
#define ifc(i)                (flag[i>>6]&(1<<((i>>1)&31)))
#define isc(i)                (flag[i>>6]|=(1<<((i>>1)&31)))
#define chk(n)                (n==2||(n>2&&(n&1)&&!ifc(n)))
#define sv()                  int t; scanf("%d",&t); while(t--)
using namespace std;
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll hcf(ll a, ll b) {if(b>a) return (hcf(b, a)); if(a%b==0) return b; return (hcf(b, a%b));} 
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
void sieve(){ int i,j,k; for(i=3;i<lmt;i+=2) if(!ifc(i)) for(j=i*i,k=i<<1;j<MX;j+=k) isc(j);}
inline void rdi(int &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void rdl(ll &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void print(int a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); pc('\n'); }
inline void prlong(ll a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); pc('\n'); }
inline void floydWarshall(vvi& dist,int V) { loop(k,0,V){ loop(i,0,V){ loop(j,0,V){ if (dist[i][k]+ dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j]; }}}}
inline void dfs(int p,vi& visit,vvi& adj){ visit[p]=true; loop(i,0,adj[p].size()){ if(visit[adj[p][i]]==false) dfs(adj[p][i],visit,adj);}}
pair<int,int> inter;
int calc(vi& v,int l,int r,int x){
    int diff=0;
	int prev=l;
	int num;
    loop(i,l,r+1){
        num=v[i];
        if(num==x){
	            if(i-prev+1>diff){
	                diff=i-prev+1;
	                inter.first=prev;
	                inter.second=i;
	            }
	            prev=i;
	    }
    }
    if(r+1-prev>diff){
	        diff=r+1-prev;
            inter.first=prev;
	        inter.second=r;    
    }
	return diff;
}
long long cost(int num){
    if(num%2==0)
        num--;
    int k=num/2;
    long long ans=(k*(k+1))+ceil((double)num/2);
    return ans;
}

int main() {
	sv(){
	    int n,num;rdi(n);
	    vi v(n);
	    long long sum=0;
	    loop(i,0,n){
	        rdi(num);
	        sum+=num;
	        v[i]=num;
	    }
	    int level=1;
	    int diff=calc(v,0,n-1,level);
	    while(diff>2){
	        level++;
	        diff=calc(v,inter.first+1,inter.second-1,level);
	    }
	    cout<<(sum-cost(diff+(level-1)*2))<<endl;
	}
	return 0;
}
