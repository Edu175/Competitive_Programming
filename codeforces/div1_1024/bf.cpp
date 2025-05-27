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
const ll MAXN=3005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return fpow(a,MOD-1+b); // 
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
ll n;
ll d[MAXN][MAXN];
void dfs(ll x, ll fa, auto &d){
	for(auto y:g[x])if(y!=fa){
		d[y]=d[x]+1;
		dfs(y,x,d);
	}
}
vv p; ll to,done;
void dfs2(ll x, ll fa){
	p.pb(x);
	if(x==to){done=1;return;}
	for(auto y:g[x])if(y!=fa){
		dfs2(y,x);
		if(done)return;
	}
	p.pop_back();
}
vv get_center(ll x, ll y){
	p.clear(); done=0; to=y;
	dfs2(x,-1);
	ll m=SZ(p);
	if(m&1)return {p[m/2]};
	return {p[m/2-1],p[m/2]};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv pot={1};
		fore(i,0,n){
			d[i][i]=0;
			dfs(i,-1,d[i]);
			pot.pb(pot.back()*3);
		}
		ll ans=0;
		map<vv,ll>mp;
		fore(mk,0,pot.back()){
			ll pr=mk;
			vv col(n);
			fore(i,0,n)col[i]=pr%3,pr/=3;
			ll res=0;
			fore(i,0,n)fore(j,0,n)if(col[i]==1&&col[j]==2){
				res=max(res,d[i][j]);
			}
			ll diam=-1,x=-1,y=-1;
			fore(i,0,n)fore(j,0,n)if(col[i]==1&&col[j]==1){
				ll cand=d[i][j];
				if(cand>diam)diam=cand,x=i,y=j;
			}
			ans+=res;
			if(diam==-1)assert(res==0);
			else {
				auto s=get_center(x,y);
				// cout<<"center "<<x<<" "<<y<<": "<<diam<<": ";
				// for(auto i:s)cout<<i<<" ";;cout<<"\n";
				mp[s]+=res;
			}
			// cout<<mk<<" "<<res<<"\n";
		}
		for(auto [s,cnt]:mp){
			cout<<"count ";
			for(auto i:s)cout<<i<<" ";
			cout<<": "<<cnt<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
