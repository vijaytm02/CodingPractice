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
#define INF                   0x3f3f3f3f
#define MAX                   1e9
#define MIN                   -1e9
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define vvi                   vector<vi>
#define vvii                  vector<vector<pair<int,int>>>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define mini                  INT_MIN
const int MX=10010896;
const int lmt=3164;
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
inline void rdi(int &x){ register int c = gc(); x = 0; int neg = 0; for(;((c<48 || c>57) && c != '-');c = gc()); if(c=='-') {neg=1;c=gc();} for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} if(neg) x=-x;}
inline void rdl(ll &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void print(int a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); pc('\n'); }
inline void prlong(ll a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); pc('\n'); }
inline void floydWarshall(vvi& dist,int V) { loop(k,0,V){ loop(i,0,V){ loop(j,0,V){ if (dist[i][k]+ dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j]; }}}}
inline void dfs(int p,vi& visit,vvi& adj){ visit[p]=true; loop(i,0,adj[p].size()){ if(visit[adj[p][i]]==false) dfs(adj[p][i],visit,adj);}}

ll N,K;
map<ll,int> mp1;
map< pair<pair<int,int>,int> , vector<ll> > hash1;
vector<ll> ans;

vector<ll> givenums(int p,int q,int k){
    if(k==1){
        vector<ll> send;
        rloop(i,p,q){
            send.pb(ans[i]);
        }
        return send;
    }
    auto it=hash1.find(mp(mp(p,q),k));
    if(it!=hash1.end())
        return it->S; 
    vector<ll> send;
    rloop(i,p,q){
        vector<ll> temp=givenums(i,q,k-1);
        loop(j,0,temp.size()){
            temp[j]+=ans[i];
            send.pb(temp[j]);
        }
    }
    hash1[mp(mp(p,q),k)]=send;
    return send;
}

int recurse(){   
    for(int i=N-1;i>=0;i--){
        auto it=mp1.rbegin();
        if(i==N-1){
            ans[i]=it->F/K;
            it->S=(it->S)-1;
            if(it->S==0)
                //mp1.erase(it->F);
        }
        ans[i]=it->F-(K-1)*ans[N-1];
        vector<ll> pp=givenums(i,N-1,K-1);
        loop(i,0,pp.size()){
            ll ppt=pp[i]+ans[i];
            mp1[ppt]--;
            if(mp1[ppt]==0)
                mp1.erase(ppt);
        }
    }
    return 1;
}


int main() {
    sv(){
        mp1.clear();
        hash1.clear();
        rdl(N);rdl(K);
        ans.assign(N,0);
        string str;
        getline(cin,str);
        istringstream iss(str);
        string token;
        while(getline(iss,token,' ')){
            ll tm=atoll(token.c_str());
            if(mp1.find(tm)==mp1.end())
                mp1[tm]=1;
            else
                mp1[tm]++;
        }        
        recurse();
        loop(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }  
    return 0;
}
