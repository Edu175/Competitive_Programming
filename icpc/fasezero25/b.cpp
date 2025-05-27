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
const ll MAXN=1e5+5;

#define bint __int128
bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
vector<bint>pi;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(bint a, bint b){return a*b%MOD;}
// int fpow(int a, ll b){
// 	if(b<0)return 0;
// 	int r=1;
// 	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
// 	return r;s
// }
ll hsh[MAXN];
const ll K=17;
vector<pair<ll,char>> g[MAXN];
ll F[K][MAXN],D[MAXN],pt[MAXN]; // my pt
void lca_dfs(ll x){
	for(auto [y,w]:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;
		pt[y]=mul(pt[x],P);
		hsh[y]=add(hsh[x],mul(pt[y],w));
		lca_dfs(y);
	}
}
void lca_init(ll n){
	D[0]=0;F[0][0]=-1;
	pt[0]=1; hsh[0]=0;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll father(ll v, ll x){ // v-ésimo padre de x
	assert(v<=D[x]);
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}

ll get(ll x, ll d){ // xd
	assert(D[x]>=d);
	ll s=D[x]-d;
	// cout<<"hsh "<<x<<" - hsh "<<father(d,x)<<" / pi "<<s<<"\n";
	ll res=mul(pi[s],sub(hsh[x],hsh[father(d,x)]));
	return res;
}
const ll MAXV=1e5+5;
vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}


int main(){FIN;
	ll n; cin>>n;
	pi.pb(1);
	fore(i,0,n+5)pi.pb(mul(pi.back(),PI));
	divisores();
	vector<pair<ii,char>>ed;
	fore(i,1,n){
		ll p; cin>>p; p--;
		ed.pb({{p,i},'.'});
	}
	fore(i,0,n-1){
		char c; cin>>c;
		ed[i].snd=c;
	}
	for(auto [ar,w]:ed){
		auto [x,y]=ar;
		g[x].pb({y,w});
	}
	lca_init(n);
	ll res=0;
	fore(x,0,n){
		ll len=D[x];
		for(auto d:divs[len])if(d<len){
			ll _d=d;
			d=len-d;
			ll h=hsh[father(len-d,x)];
			// cout<<"\n";
			// cout<<x<<": "<<_d<<"\n";
			if(h==get(x,d)){
				res=max(res,_d);
				// cout<<"good";
				break;
			}
			// cout<<"\n";
		}
	}
	cout<<res<<"\n";
	return 0;
}
