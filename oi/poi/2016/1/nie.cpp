#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,MAXM=1e6+5,MOD=1e9+7;

vector<ii>g[MAXN];
ll fa[MAXN],D[MAXN],has[MAXN],vis[MAXN],k=-1,l,flag=1,S[MAXN],E[MAXN];
ll vised[MAXM];
ll cnt=0;
vector<ll>ord;
void dfs(ll x){
	vis[x]=1;
	S[x]=cnt++;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			fa[y]=x;
			dfs(y);
		}
		else {
			if(k==-1)k=D[x]-D[y]+1;
			else flag&=k==D[x]-D[y]+1;
			has[x]=1;
		}
	}
	ord.pb(x);
	E[x]=cnt;
}

void out(){
	cout<<"NIE\n";
	exit(0);
}
ll to2(ll n){return n*(n-1)/2;}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fa[0]=-1;
	dfs(0);
	// fore(i,0,n)cout<<i<<": "<<D[i]<<" "<<fa[i]<<"\n";
	if(!flag){cout<<"NIE\n";return 0;}
	ll res=0;
	fore(i,0,n)res+=has[i];
	if(!res){cout<<"BRAK\n";return 0;}
	ll l=k/2;
	vector<ll>mat(n);
	set<ii>st;
	fore(i,0,n)if(has[i])st.insert({S[i],i});
	for(auto x:ord){
		vector<ll>h;
		vector<ii>pop;
		for(auto it=st.lower_bound({S[x]+1,-1});it!=st.end()
		&&it->fst<E[x];it++){
			if(D[it->snd]-D[x]>=k-1)pop.pb(*it);
			else h.pb(it->snd);
		}
		if(has[x]){
			for(auto i:h){
				if(D[i]-D[x]!=l-1||mat[i])out();
			}
			res+=to2(SZ(h)+1);
			for(auto i:h)mat[i]=1,st.erase({S[i],i});
			mat[x]=1,st.erase({S[x],x});
		}
		
		for(auto i:pop)st.erase(i);
	}
	
	if(!flag){cout<<"NIE\n";return 0;}
	// cout<<"hay "<<res<<" ciclos\n";
	cout<<"TAK\n"<<k<<" ";
	res=res%MOD*k*2%MOD;
	cout<<res<<"\n";
	return 0;
}