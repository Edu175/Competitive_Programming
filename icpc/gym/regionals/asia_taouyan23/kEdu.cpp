#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dbg(v){cout<<#v<<": ";for(auto i:v)cout<<i<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e4+5;

vv dp[MAXN][3];

vector<ii> g[MAXN];
ll a[MAXN]; // given a, calc est

ll f(ll x, ll col, ll fa, ll rev){
	assert(!(!col&&a[x])); // no pregunto
	auto &res=dp[x][col][rev];
	if(res!=-1)return res;
	if(!col){
		ll q=0;
		for(auto [y,rev]:g[x])if(y!=fa)q+=!f(y,1,x,rev);
		res=q<=(fa==-1);
	}
	else {
		res=!a[x];
		if(!res)for(auto [y,rev]:g[x])if(y!=fa)res|=f(y,0,x,rev);
	}
	return res;
}

vv get(vv _a){
	ll n=SZ(_a);
	fore(x,0,n){
		a[x]=_a[x];
		fore(j,0,3)dp[x][j]=vv(SZ(g[x])+1,-1);
	}
	vv est(n);
	fore(x,0,n)est[x]=!f(x,a[x],-1,SZ(g[x]));
	return est;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb({i,SZ(g[i])});
			g[i].pb({p,SZ(g[p])-1});
		}
		vv a(n),b(n);
		fore(w,0,2)fore(i,0,k){
			ll x; cin>>x; x--;
			(w?b:a)[x]=1;
		}
		// dbg(a)
		// dbg(b)
		ll flag=1;
		fore(x,0,n)for(auto [y,dfkjg]:g[x])
			flag&=!(a[x]&&a[y])&&!(b[x]&&b[y]);
		if(!flag){cout<<"0\n";continue;} // invalid a or b
		auto estA=get(a);
		// dbg(estA)
		auto estB=get(b);
		// dbg(estB)
		flag&=estA==estB;
		vv vis(n);
		ll qA=0,qB=0;
		auto dfs=[&](ll x, auto &&dfs)->void{
			qA+=a[x];
			qB+=b[x];
			vis[x]=1;
			for(auto [y,sdkjf]:g[x])if(!vis[y]&&!estA[y])
				dfs(y,dfs);
		};
		fore(x,0,n)if(!vis[x]){
			if(estA[x])flag&=a[x]==b[x];
			else {
				qA=qB=0;
				dfs(x,dfs);
				flag&=qA==qB;
			}
		}
		cout<<flag<<"\n";
	}
	return 0;
}