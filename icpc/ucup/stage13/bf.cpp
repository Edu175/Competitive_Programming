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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=2e5+5;
vector<ll> g[MAXN];
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<ii>ed;
	fore(i,0,n)fore(j,i+1,n)ed.pb({a[i],a[j]});
	auto is=[&](vector<ii>ed)->bool{
		fore(i,0,n){
			vis[i]=0;
			g[i].clear();
		}
		for(auto [x,y]:ed)g[x].pb(y);
		vector<ll>r(n);
		for(ll i=n-1;i>=0;i--){
			ll x=a[i];
			r[i]=i+1;
			vv v={i};
			while(r[i]<n&&x>a[r[i]]){
				v.pb(r[i]);
				r[i]=r[r[i]];
			}
			dfs(a[i]);
			vis[a[i]]=0;
			fore(i,1,SZ(v))if(!vis[a[v[i]]])return 0;
		}
		return 1;
	};
	ll res=0;
	fore(mk,0,1<<SZ(ed)){
		vector<ii>edi;
		fore(j,0,SZ(ed))if(mk>>j&1)edi.pb(ed[j]);
		if(is(edi)){
			// for(auto [x,y]:edi)cout<<x<<","<<y<<" ";;cout<<"\n";
			res++;
		}
	}
	cout<<res%MOD<<"\n";
	return 0;
}
