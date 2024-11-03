#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXQ=1e5+5;
int uf[MAXQ];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){ET
	ll n,L,R; cin>>n>>L>>R;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll q; cin>>q;
	vv ans(q);
	vector<vv> qs(n+5);
	vector<vector<ii>>upds(n+5);
	fore(i,0,q){
		ll s,e,x; cin>>s>>e>>x; s--;
		upds[s].pb({i,x});
		qs[e].pb(i);
	}
	uf_init();
	set<ii>st;
	vv v(q); ll del=0;
	auto value=[&](ll x){return v[uf_find(x)]+del;};
	fore(t,0,n+5){
		// fore(i,0,q)cout<<value(i)<<" ";;cout<<"\n";
		for(auto x:qs[t])ans[x]=value(x);
		for(auto [x,val]:upds[t]){
			v[x]=val-del;
			st.insert({v[x],x});
		}
		if(t<n)del+=a[t];
		
		// Upper
		ll p=-1;
		while(SZ(st)){
			ll x=prev(st.end())->snd;
			if(value(x)<=R)break;
			st.erase(prev(st.end()));
			if(p==-1)p=x;
			else uf_join(p,x);
			p=uf_find(p); // no hace falta
		}
		if(p!=-1){
			v[p]=R-del;
			st.insert({v[p],p});
		}
		
		//Lower
		p=-1;
		while(SZ(st)){
			ll x=(st.begin())->snd;
			if(value(x)>=L)break;
			st.erase(st.begin());
			if(p==-1)p=x;
			else uf_join(p,x);
			p=uf_find(p); // no hace falta
		}
		if(p!=-1){
			v[p]=L-del;
			st.insert({v[p],p});
		}
	}
	fore(i,0,q)cout<<ans[i]<<"\n";
}