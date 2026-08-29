#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll maxn=2e5+5;
ll uf[maxn];
ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool join(ll x, ll y){
	x=find(x),y=find(y);
	if(x==y) return false;
	if(uf[x]>uf[y]) swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
	return true;
}
const ll INF=1e10;
ii kruskal(vi &ar, vv &w, vv &p, ll n){
	fore(i,0,n) uf[i]=-1;
	ll r=0;
	ll mn=INF;
	ll m=SZ(ar);
	fore(i,0,m){
		auto [u,v]=ar[p[i]];
		if(join(u,v)){
			r+=w[p[i]];
			mn=min(w[p[i]],mn);
		}
	}
	return {r,uf[find(0)]==-n?mn:INF};
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,m,k; cin>>n>>m>>k;
		vi ar;
		vv w;
		vv p(m); iota(ALL(p),0);
		vi ar2;
		vv w2;
		vv p2;
		fore(i,0,m){
			ll u,v,t; cin>>u>>v>>t;
			u--,v--;
			ar.pb({u,v});
			w.pb(max(t-k,0ll));
			if(t<=k){
				ar2.pb({u,v});
				w2.pb(k-t);
			}
		}	
		p2.resize(SZ(ar2)); iota(ALL(p2),0);
		sort(ALL(p),[&](ll i, ll j){
			return w[i]<w[j];
		});
		sort(ALL(p2),[&](ll i, ll j){
			return w2[i]<w2[j];
		});
		ll rt1=kruskal(ar2,w2,p2,n).snd;
		if(rt1<INF){
			fore(i,0,m)if(w[i]){
				rt1=min(rt1,w[i]);
			} 
		}
		else{
			rt1=kruskal(ar,w,p,n).fst;
		}
		cout<<rt1<<"\n";
	}
	return 0;
}
