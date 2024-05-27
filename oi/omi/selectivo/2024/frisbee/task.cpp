#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfkjhg:v)cout<<dfkjhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=16;

vector<ll> g[MAXN]; ll m; // m = number of nodes
ll F[K][MAXN],D[MAXN];

ii d[MAXN];
ll L[MAXN],R[MAXN];
vector<ll>sp[MAXN];
ll pos[MAXN];
void lca_dfs(ll x){
	vector<ii>a;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		F[0][y]=x;
//		d[y]={2*MAXN,2*MAXN};
		a.pb({L[y],y});
	}
	sort(ALL(a));
	sp[x].resize(SZ(a)+1);
	fore(i,0,SZ(a)){
		auto y=a[i].snd;
		g[x][i]=y;
		pos[y]=i;
		sp[x][i+1]=sp[x][i]+R[y]-L[y]-1;
	}
	fore(i,0,SZ(g[x])){
		auto y=g[x][i];
		d[y]={L[y]-L[x]-sp[x][i],R[x]-R[y]-(sp[x][SZ(g[x])]-sp[x][i+1])};
		d[y].fst=min(d[y].fst,d[y].snd+2);
		d[y].snd=min(d[y].snd,d[y].fst+2);
		d[y].fst+=d[x].fst;
		d[y].snd+=d[x].snd;
	}
	for(auto y:g[x])lca_dfs(y);
}
ll rt;
void lca_init(){
	D[rt]=0,F[0][rt]=-1;
	lca_dfs(rt);
	fore(k,1,K)fore(x,0,m)F[k][x]=F[k-1][x]==-1?-1:F[k-1][F[k-1][x]];
}

ii lca(ll x, ll y){
	ll sw=0;
	if(D[x]<D[y])swap(x,y),sw=1;
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
//	if(F[0][x]==y){
//		if(sw)swap(x,y);
//		return {x,y};
//	}
	assert(x!=y);
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		x=F[k][x];
		y=F[y][x];
	}
	if(sw)swap(x,y);
	return {x,y};
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ii,ll>>a;
	fore(i,0,n){
		L[i]=i,R[i]=(i+1)%n;
		if(i==n-1)swap(L[i],R[i]);
		a.pb({{L[i],-R[i]},i});
	}
	rt=n-1;
	fore(i,0,n-3){
		ll l,r; cin>>l>>r; l--,r--;
		if(l>r)swap(l,r);
		L[n+i]=l,R[n+i]=r;
		a.pb({{l,-r},n+i});
	}
	/*for(auto i:a){
		cout<<"{"<<i.fst.fst<<","<<i.fst.snd<<" "<<i.snd<<"} ";
	}
	cout<<endl;*/
	m=SZ(a);
	sort(ALL(a));
//	for(auto i:a){
//		cout<<"{"<<i.fst.fst<<","<<i.fst.snd<<" "<<i.snd<<"} ";
//	}
//	cout<<endl;
	vector<ll>b={a[0].snd};
	fore(i,1,SZ(a)){
		auto x=a[i].snd;
		while(R[b.back()]<R[x])b.pop_back();
//		cout<<b.back()<<" --> "<<x<<"\n";
		g[b.back()].pb(x);
		b.pb(x);
	}
	lca_init();
//	fore(i,0,m){cout<<i<<": ";imp(g[i]);}
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--,e--;
		if(e<s)swap(s,e);
		if(e-s<=1){
			cout<<e-s<<"\n";
			continue;
		}
		auto query=[&](ll i, ll j){
			vector<ll>dis(4);
			ll x=s+i; dis[0]=i,dis[1]=!i;
			ll y=e+j; dis[2]=j,dis[3]=!j;
			//if(x==y)return ;
			cout<<"query "<<i<<" "<<j<<": "<<x<<","<<y<<"\n";
			ii pad=lca(x,y);
			auto px=pad.fst,py=pad.snd;
			dis[0]+=d[x].fst-d[px].fst;
			dis[1]+=d[x].snd-d[px].snd;
			dis[2]+=d[y].fst-d[py].fst;
			dis[3]+=d[y].snd-d[py].snd;
			auto p=F[0][px];
//			cout<<"query "<<i<<" "<<j<<": "<<x<<","<<y<<" | "<<px<<","<<py<<" "<<p<<endl;
//			imp(dis);
			ll res=3*n;
			ll k=SZ(g[p]);
			auto dist=[&](ll i, ll j){
				ll pi=i?R[px]:L[px];
				ll pj=j?R[py]:L[py];
				ll indi=pos[px],indj=pos[py];
//				cout<<"dist "<<i<<","<<j<<":\n";
//				cout<<pi<<" "<<pj<<" | "<<indi<<" "<<indj<<"\n";
				ll resi=min(pj-pi-(sp[p][indj+j]-sp[p][indi+i]),
						1+pi+R[p]-pj-(sp[p][k]-sp[p][indj+j]+sp[p][indi+i]));
//				cout<<resi<<" --> ";
				resi+=dis[i]+dis[2+j];
//				cout<<resi<<"\n";
				return resi;
			};
			fore(i,0,2)fore(j,0,2)res=min(res,dist(i,j));
//			cout<<" = "<<res<<"\n";
			return res;
		};
		ll ans=min(e-s,(s-e+n)%n);
		fore(i,0,2)fore(j,0,2)if(e+j<n-1)ans=min(ans,query(i,j));
		cout<<ans<<endl;
	}
	return 0;
}
