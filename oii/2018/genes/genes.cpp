#include "genes.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdkfjg:v)cout<<sdkfjg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e4+5;

ll col[MAXN],id[MAXN],good[MAXN];
vector<ll>comp[MAXN];

ll join(ll x, ll y){
	ll _x=x,_y=y;
	x=id[x],y=id[y];
	// cout<<"\ngood "<<x+1<<","<<y+1<<": "<<good[x]<<" "<<good[y]<<"\n";
	if(good[x]&&good[y])return 0;
	if(x==y){
		if(good[x])return 0;
		if(col[_x]==col[_y])return good[x]=1;
		return 0;
	}
	ll z=col[_x]==col[_y];
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	for(auto i:comp[y])id[i]=x,col[i]^=z,comp[x].pb(i);
	good[x]|=good[y];
	comp[y].clear();
	return 1;
}
// ll join(ll x, ll y){
// 	ll ret=uf_join(x,y);
// 	// cout<<"join "<<x+1<<","<<y+1<<": "<<ret<<"\n";
// 	return ret;
// }
ll n,m;
vector<ll> g[MAXN];
ll vis[MAXN]; ii p[MAXN];
ll c[MAXN],var,done;
ll ask(ll x, ll y){return measureBacteria(x+1,y+1);}
// string cv(ii a){return to_string(a.fst)+","+to_string(a.snd);}
ll get(ii a, ii b, ll c){
	// cout<<"get "<<cv(a)<<" "<<cv(b)<<" = "<<c<<endl;
	return (c-(a.fst+b.fst))/(a.snd+b.snd);
}
vector<ll>h;
void dfs(ll x){
	vis[x]=1;
	h.pb(x);
	for(auto y:g[x]){
		if(vis[y]){
			if(c[x]==c[y]&&!done){
				done=1;
				var=get(p[x],p[y],ask(x,y));
			}
		}
		else {
			c[y]=c[x]^1;
			ll s=ask(x,y);
			p[y].snd=-p[x].snd;
			p[y].fst=s-p[x].fst;
			dfs(y);
		}
	}
}

void tryScience(int T, int C, int cost[], int X[], int Y[]) {
	n=T,m=C;
	fore(i,0,n){
		id[i]=i;
		comp[i]={i};
	}
	vector<ll>per;
	fore(i,0,m)per.pb(i),X[i]--,Y[i]--;
	sort(ALL(per),[&](ll i, ll j){return cost[i]<cost[j];});
	vector<ll>is(m),us(n);
	for(auto i:per){
		is[i]=join(X[i],Y[i]);
	}
	// ll ans=0;
	fore(i,0,m){
		ll x=X[i],y=Y[i];
		if(is[i]&&good[id[x]])g[x].pb(y),g[y].pb(x),us[x]=us[y]=1;
	}
	vector<ll>val(n);
	fore(x,0,n)if(us[x]&&!vis[x]){
		h.clear();
		p[x]={0,1};
		done=0;
		dfs(x);
		for(auto i:h)val[i]=p[i].fst+var*p[i].snd;
	}
	vector<int> xs;
	vector<ll>vs;
	fore(x,0,n)if(us[x]){
		xs.pb(x+1),vs.pb(val[x]);
	}
	// imp(xs); imp(vs);
	report(SZ(xs),xs.data(),vs.data());
}