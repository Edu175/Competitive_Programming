#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
struct tr{
	ll x,y,z;
};

vi red(vi v){
	sort(ALL(v));
	vi r={v[0]};
	for(auto x: v)if(x!=r.back())r.pb(x);
	return r;	
}
const ll maxn=6*(2e5+5);
vv g[maxn];
ll vis[maxn];

ll nxt(ll c){c++; return c<3?c:0;}
vv bu;
bool dfs(ll u, ll c){
	vis[u]=c;
	bu.pb(u);
	c=nxt(c);
	for(auto v:g[u])if(vis[v]<3){
		if(vis[v]<0){
			if(!dfs(v,c)) return false;
		}
		if(vis[v]!=c) return false;
	}
	return true;
}
bool rt=0;
void mdfs(ll i){
	if(!dfs(i,0)) rt=1;
	for(auto u:bu) vis[u]=3;
	bu.clear();
}
ii mkp(ll a, ll b){
	if(a>b) swap(a,b);
	return {a,b};
}
int main(){
	JET
	mset(vis,-1);
	ll _; cin>>_; while(_--){
		ll m; cin>>m;
		vi v;
		vector<tr> t;
		fore(i,0,m){
			ll a,b,c; cin>>a>>b>>c;
			t.pb({a,b,c});
			v.pb(mkp(a,b));
			v.pb(mkp(b,c));
			v.pb(mkp(a,c));

		}
		v=red(v);
		fore(i,0,m){
			ll a=t[i].x,b=t[i].y,c=t[i].z;
			vv id={a,b,c};
			do{
				ll x=id[0],y=id[1],z=id[2];
				ll p1=lower_bound(ALL(v),mkp(x,y))-v.begin();
				ll p2=lower_bound(ALL(v),mkp(y,z))-v.begin();
				g[p1].pb(p2);
			}while(next_permutation(ALL(id)));
			
		}
		fore(i,0,SZ(v)) if(vis[i]<0) mdfs(i);
		cout<<(rt?"yes\n":"no\n");
		fore(i,0,SZ(v)) g[i].clear(),vis[i]=-1;
		rt=0; 
		// cout<<"CLEAR!";
	}
	return 0;
}