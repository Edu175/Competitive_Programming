#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4e5+5;
#define bint __int128
bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
ll a[MAXN],b[MAXN],ta[MAXN],tb[MAXN];
ll k;
vv g[MAXN];
void dfs(ll x, ll *a){
	for(auto y:g[x])if(a[y]==-1){
		a[y]=(a[x]+1)%k;
		dfs(y,a);
	}
}
ll cnt(vv a){return accumulate(ALL(a),0ll);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		auto doit=[&](ll* a, ll* ta){
			fore(i,0,n){
				g[i].clear();
				a[i]=-1;
			}
			fore(i,0,n)cin>>ta[i];
			ll m; cin>>m;
			fore(i,0,m){
				ll u,v; cin>>u>>v; u--,v--;
				g[u].pb(v);
			}
			a[0]=1;
			dfs(0,a);
		};
		doit(a,ta);
		doit(b,tb);
		vv aout(k),ain(k);
		vv bout(k),bin(k);
		fore(i,0,n){
			(ta[i]?aout:ain)[a[i]]++;
			(tb[i]?bout:bin)[b[i]]++;
		}
		// imp(aout)
		// imp(ain)
		// imp(bout)
		// imp(bin)
		rotate(ain.begin(),ain.begin()+2%k,ain.end());
		vector<bint> pot(k+1);
		pot[0]=1;
		fore(i,1,k+1)pot[i]=pot[i-1]*P%MOD;
		auto get=[&](vv a){
			ll h=0;
			fore(i,0,SZ(a))h=(h+pot[i]*a[i])%MOD;
			return h;
		};
		auto rot=[&](ll &h, vv &a, ll s){ // izq
			h=(h-a[s]+a[s]*pot[k]+MOD)%MOD;
			h=h*PI%MOD;
		};
		ll haout=get(aout),hain=get(ain);
		ll hbout=get(bout),hbin=get(bin);
		ll flag=0;
		fore(i,0,k+5){
			flag|=haout==hbin&&hain==hbout;
			rot(hbin,bin,i%k);
			rot(hbout,bout,i%k);
		}
		if(flag||(cnt(aout)+cnt(bin)==0)||(cnt(bout)+cnt(ain)==0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
