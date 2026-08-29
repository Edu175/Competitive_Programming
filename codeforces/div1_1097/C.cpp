#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
xl euclid(xl a, xl b, xl &x, xl &y) {
	if (!b) return x = 1, y = 0, a;
	xl d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
pair<xl,xl> crt(xl a, xl m, xl b, xl n) {
	if (n > m) swap(a, b), swap(m, n);
	xl x, y, g = euclid(m, n, x, y);
	// assert((a - b) % g == 0); // else no solution
	if((a - b) % g != 0)return {-1,1};
	x = (b - a) % n * x % n / g * m + a;
	return {(x < 0 ? x + m*n/g : x),m*n/g};
}

const ll MAXN=5e5+5;
vector<ll> g[MAXN];
// ll fa[MAXN];
ll wf[MAXN],D[MAXN];
const ll MX=2e18;
ii eq[MAXN];
// ll  pinga=0;
void dfs0(ll x, ll d, xl a, xl m){
	// pinga++;
	D[x]=d;
	if(a==-1||a>=MX)return;
	ll z=SZ(g[x]);
	eq[x]={a,min(m,(xl)MX)};
	if(!z)return;
	if(m>MX){ // deterministic
		ll i=(a+d)%z;
		ll y=g[x][i];
		dfs0(y,d+wf[y],a,m);
		return;
	}
	fore(i,0,z){
		ll y=g[x][i];
		xl r=(i-d%z+z)%z;
		auto [na,nm]=crt(a,m,r,z);
		dfs0(y,d+wf[y],na,nm);
	}
}

ll S[MAXN],E[MAXN];
ll cnt=0;
void dfs1(ll x){
	S[x]=cnt++;
	for(auto y:g[x])dfs1(y);
	E[x]=cnt;
}
bool holds(ll s, ll x){
	return s%eq[x].snd==eq[x].fst;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
			eq[i]={-1,1};
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,1,n)cin>>wf[i];
		dfs0(0,0,0,1);
		// cerr<<pinga<<"\n";
		// dfs0(0,0,0,1);
		// cerr<<pinga<<"\n";
		// fore(i,0,n){
		// 	cout<<i+1<<": "<<eq[i].fst<<","<<eq[i].snd<<"\n";
		// }
		vv sz(n);
		for(ll x=n-1;x>=0;x--){
			sz[x]=1;
			for(auto y:g[x])sz[x]+=sz[y];
		}
		vector<vv> oriG(n);
		fore(i,0,n)oriG[i]=g[i];
		fore(x,0,n)sort(ALL(g[x]),[&](ll a, ll b){return sz[a]>sz[b];});
		cnt=0;
		dfs1(0);
		vector<ii> eqs(n);
		vv pos(n);
		// vv ish(n);
		fore(i,0,n){
			eqs[S[i]]=eq[i];
			// ish[S[i]]=SZ(g[i])==0;
			pos[S[i]]=i;
		}
		// show(pos)
		fore(i,0,q){
			ll s; cin>>s;
			ll x=0;
			while(1){
				// cerr<<"vuelta "<<x+1<<"\n";
				ll l=S[x],r=E[x];
				while(r-l>1){
					ll h=(r==E[x]?r-1:((l+r)>>1));
					auto &[a,m]=eqs[h];
					if((s<m?s:s%m)==a)l=h;
					else r=h;
				}
				ll u=pos[l]; // last that holds
				// cerr<<l<<" "<<u+1<<" l u"<<endl;
				x=u;
				// assert(holds(s,x));
				// cerr<<"sz "<<SZ(g[u])<<"\n";
				if(!SZ(g[u]))break;
				assert(eq[u].fst!=-1);
				ll i=(s+D[u])%SZ(g[u]);
				ll y=oriG[u][i];
				x=y;
				// assert(holds(s,x));
			}
			ll res=x;
			// cerr<<s<<": "<<res<<endl;
			assert(holds(s,res));
			cout<<res+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
