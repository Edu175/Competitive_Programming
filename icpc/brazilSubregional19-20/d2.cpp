#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

const ll MAXN=1e5+5;

vector<ll> g[MAXN];

ii h[MAXN];
ll vis[MAXN];
void dfs(ll x){
	h[x]={-1,-1};
	if(!SZ(g[x]))h[x]={0,x};
	else {
		for(auto y:g[x]){
			dfs(y);
			h[x]=max(h[x],h[y]);
		}
	}
	h[x].fst++;
}

int main(){
	FIN
	ll n,k; cin>>n>>k;
	vector<ll>p(n); p[0]=-1;
	fore(i,1,n){
		cin>>p[i]; p[i]--;
		g[p[i]].pb(i);
	}
	dfs(0);
	set<ii>st;
	fore(i,0,n)st.insert(h[i]);
	ll res=0;
	fore(_,0,k){
		if(!SZ(st))break;
		auto [d,x]=*prev(st.end());
		res+=d;
		while(x!=-1&&!vis[x]){
			st.erase(h[x]);
			vis[x]=1;
			x=p[x];
		}
	}
	cout<<res<<"\n";
	return 0;
} 