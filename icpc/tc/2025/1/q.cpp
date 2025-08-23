#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105,INF=2e9;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ii a[MAXN];

ll d(ll i, ll j){
	return abs(a[i].fst-a[j].fst)+abs(a[i].snd-a[j].snd);
}
vv g[MAXN];
ll vis[MAXN];
vv nod;
void dfs(ll x){
	vis[x]=1;
	nod.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

ll mem[MAXN][MAXN];
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=add(nCr(n-1,k-1),nCr(n-1,k));
}

int main(){
	JET
	mset(mem,-1);
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n){
		vv ds(n);
		fore(j,0,n){
			if(i!=j){
				ds[j]=d(i,j);
			}
		}
		ds[i]=INF;
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){
			return ds[i]<ds[j];
		});
		fore(_,0,n){
			g[i].pb(per[_]);
			// g[per[_]].pb(i);
			if(_<n-1&&ds[per[_]]!=ds[per[_+1]])break;
		}
	}
	
	set<vv> comps;
	fore(i,0,n){
		nod.clear();
		mset(vis,0);
		dfs(i);
		set<ll>st;
		for(auto i:nod)for(auto j:nod)if(i!=j)st.insert(d(i,j));
		if(SZ(st)>1){
			for(auto j:nod)vis[j]=0;
			nod={i};
		}
		sort(ALL(nod));
		comps.insert(nod);
	}
	vv zs;
	for(auto i:comps)zs.pb(SZ(i));
	// for(auto i:zs)cout<<i<<" ";;cout<<"\n";
	ll m=SZ(zs);
	vector<vv> dp(m+1,vv(n+3));
	vv fc(n+5); fc[0]=1;
	fore(i,1,n+3)fc[i]=mul(i,fc[i-1]);
	fore(k,0,n+1)dp[m][k]=mul(nCr(n,k),fc[k]);
	
	for(ll i=m-1;i>=0;i--)fore(k,0,n+1){
		auto &res=dp[i][k];
		res=0;
		if(k+1<=n)res=add(res,dp[i+1][k+1]);
		if(zs[i]!=1&&k+zs[i]<=n)res=add(res,dp[i+1][k+zs[i]]);
	}
	ll res=dp[0][0];
	cout<<res<<"\n";
	return 0;
}
