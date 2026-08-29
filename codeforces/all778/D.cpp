#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXV=2e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return fpow(b,MOD-1+e);
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll inv(ll a){return fpow(a,MOD-2);}

int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before		O(log(n))
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}

map<ll,ll> now,mx;
// now: ys_p-xs_p max con 0
// mx: max historico de xs_p-ys_p
const ll MAXN=MAXV;
vector<array<ll,3>> g[MAXN];
ll res=0;
void dfs(ll u, ll fa, ll cur){ // cur is 'now' in number
	res=add(res,cur);
	// cout<<u<<": "<<cur<<"\n";
	for(auto [v,x,y]:g[u])if(v!=fa){
		auto fx=fact(x);
		auto fy=fact(y);
		auto dif=fy; // y-x
		for(auto [p,e]:fx)dif[p]-=e;
		
		auto ncur=cur;
		for(auto [p,e]:dif){
			ll val=fpow(p,now[p]);
			ncur=mul(ncur,inv(val));
			
			now[p]+=e;
			val=fpow(p,now[p]);
			ncur=mul(ncur,val);
			
			mx[p]=max(mx[p],-now[p]);
		}
		dfs(v,u,ncur);
		for(auto [p,e]:dif)now[p]-=e;
	}
}

int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(_,0,n-1){
			ll i,j,x,y; cin>>i>>j>>x>>y; i--,j--;
			g[i].pb({j,x,y});
			g[j].pb({i,y,x});
		}
		res=0;
		now.clear();
		mx.clear();
		dfs(0,-1,1);
		ll rt=1;
		for(auto [p,e]:mx)rt=mul(rt,fpow(p,e));
		// cout<<"rt: "<<rt<<"\n";
		res=mul(res,rt);
		cout<<res<<"\n";
	}
	return 0;
}
