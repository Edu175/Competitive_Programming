#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll C=6;
vector<ll>go6={1,2,2,1,4,4,1,4,1,1,4,4,3,4,4,4,2,3,2,3,3,3,3,3,3,1,3,3,3,1,3,3,1,2,3,3,4,3,3,2,1,2,2,1,3,2,1,2,2,2,2,1,1,3,1,1,1,2,3,0,2,0,2,3};
vector<ll>go5={1,2,3,3,1,3,3,2,1,2,2,1,3,2,1,2,2,2,2,1,1,3,1,1,1,2,3,0,2,0,2,3};

const ll MAXN=1ll<<C;
ll n,N;
vector<ii> g[MAXN];
ll vis[MAXN];

vector<bool> cv(ll mk, ll n=n){
	vector<bool> r;
	fore(i,0,n)r.pb(mk>>i&1);
	return r;
}
ll cv(vector<bool>v, ll n=n){
	ll mk=0;
	fore(i,0,n)mk|=ll(v[i])<<i;
	return mk;
}

ll dp[MAXN],go[MAXN],to[MAXN];
ll ppc(ll n){return __builtin_popcountll(n);}
ll mx(ll x, ll y){
	if(ppc(x)==ppc(y))return max(x,y);
	if(ppc(x)>=ppc(y))return x;
	return y;
}
void dfs(ll x){
	dp[x]=x;
	go[x]=to[x]=-1;
	vis[x]=1;
	for(auto [y,i]:g[x]){
		if(!vis[y])dfs(y);
		ll bef=dp[x];
		dp[x]=mx(dp[x],dp[y]);
		if(dp[x]!=bef)go[x]=i,to[x]=y;
	}
}
string pr(vector<bool> v){
	string s;
	for(auto i:v)s.pb('0'+i);
	return s;
}
vector<ll> bf(vector<bool> v){
	// cout<<"bf "<<pr(v)<<endl;
	n=SZ(v),N=1ll<<n;
	fore(i,0,N){
		g[i].clear();
		vis[i]=0;
	}
	fore(mk,0,N){
		auto x=cv(mk);
		fore(i,1,n-1){
			auto v=x;
			// imp(v);
			// cout<<endl;
			v[i-1]=!v[i-1]&&!v[i];
			v[i+1]=!v[i+1]&&!v[i];
			ll y=cv(v);
			g[mk].pb({y,i});
		}
	}
	ll mk=cv(v);
	dfs(mk);
	vector<ll>ops;
	ll x=mk;
	while(go[x]!=-1){
		/*cout<<pr(cv(x))<<endl,*/
		ops.pb(go[x]);
		x=to[x];
	}
	cerr<<"v "<<pr(cv(x))<<"\n";
	return ops;
}
void adv(vector<bool> &v, ll i){
	// cout<<pr(v)<<" "<<i<<endl;
	v[i-1]=!v[i-1]&&!v[i];
	v[i+1]=!v[i+1]&&!v[i];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		// cout<<endl;
		cerr<<"\n";
		ll n; cin>>n;
		string s; cin>>s;
		vector<bool> v;
		fore(i,0,n)v.pb(s[i]-'0');
		if(v==vector<bool>(n,1)){
			cout<<"0\n";
			continue;
		}
		if(n<C){
			auto res=bf(v);
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
			continue;
		}
		vector<ll>res;
		ll did=0;
		for(ll i=n-6;i>=0;i-=3){
			did|=i==0;
			ll mk=0;
			fore(j,0,6)mk+=ll(v[i+j])<<j;
			auto u=cv(mk,6);
			while(go6[mk]){
				ll p=go6[mk];
				// cout<<p<<endl;
				res.pb(i+p);
				adv(u,p);
				mk=cv(u,6);
			}
			fore(j,0,6)v[i+j]=u[j];
		}
		if(!did){
			ll i=0;
			ll mk=0;
			fore(j,0,6)mk+=ll(v[i+j])<<j;
			auto u=cv(mk,6);
			while(go6[mk]){
				ll p=go6[mk];
				res.pb(i+p);
				adv(u,p);
				mk=cv(u,6);
			}
			fore(j,0,6)v[i+j]=u[j];
		}
		cerr<<"v "<<pr(v)<<"\n";
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
