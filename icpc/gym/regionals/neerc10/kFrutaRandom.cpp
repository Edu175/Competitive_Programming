#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
void pinchilon(){
	#ifdef ONLINE_JUDGE
	freopen("kgraph.in","r",stdin);
	freopen("kgraph.out","w",stdout);
	#endif
}
random_device rd;
mt19937 rng(rd());
const ll MAXN=1e4+5;
vv g[MAXN];
// const double TL=0.9;
int main(){pinchilon();
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll k=0;
	vv prio,rest;
	fore(x,0,n)k=max(k,SZ(g[x]));
	fore(x,0,n){
		if(SZ(g[x])==k)prio.pb(x);
		else rest.pb(x);
	}
	if(k%2==0)k++;
	vv res;
	auto proba=[&](){
		shuffle(ALL(prio),rng);
		shuffle(ALL(rest),rng);
		vv ord=prio;
		for(auto i:rest)ord.pb(i);
		vv col(n,-1);
		vv no(k);
		for(auto x:ord){
			vv is(SZ(g[x])+3);
			ll cnt=0;
			for(auto y:g[x])if(col[y]!=-1){
				cnt+=!no[col[y]];
				no[col[y]]=1;
			}
			ll uso=-1;
			if(cnt*2<k){
				uso=rng()%k;
				while(no[uso])uso=rng()%k;
			}
			else {
				vv dis;
				fore(i,0,k)if(!no[i])dis.pb(i);
				if(!SZ(dis))return;
				uso=dis[rng()%SZ(dis)];
			}
			for(auto y:g[x])if(col[y]!=-1)no[col[y]]=0;
			col[x]=uso;
		}
		res=col;
	};
	while(!SZ(res))proba();
	cout<<k<<"\n";
	for(auto i:res)cout<<i+1<<"\n";
}