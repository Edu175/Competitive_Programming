#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e10;
struct FT{
	vv s;
	FT(int n):s(n,INF){}
	void update(int pos, ll dif){
		for(;pos<SZ(s);pos|=pos+1)s[pos]=min(s[pos],dif);
	}
	ll query(int pos){
		ll res = INF;
		for(;pos>0;pos&=pos-1)res =min(res, s[pos-1]);
		return res;
	}
};

struct FT2{
	vector<vv> ys; vector<FT> ft;
	FT2(int limx):ys(limx){}
	void fakeUpdate(int x, int y){
		for(;x<SZ(ys);x|=x+1)ys[x].pb(y);
	}
	void init(){
		for(vv &v : ys)sort(ALL(v)),ft.emplace_back(SZ(v));
	}
	int ind(int x, int y){
		return(int)(lower_bound(ALL(ys[x]),y) - ys[x].begin()); 
	}
	void update(int x, int y, ll dif){
		for(;x<SZ(ys);x|=x+1)ft[x].update(ind(x,y),dif);
	}
	ll query(int x, int y){
		ll res = INF;
		for(;x;x&=x-1)res=min(res,ft[x-1].query(ind(x-1,y)));
		return res;
	}
};

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<array<ll,5>> all;
	vector<ll> ts(n);
	vv vals;
	fore(i,0,n){
		ll s,f,t; cin>>s>>f>>t;
		all.pb({t,1,s,f,-1});
		vals.pb(s);
		ts[i]=t;
	}
	fore(i,0,m){
		ll l,r,b; cin>>l>>r>>b;
		vals.pb(l);
		all.pb({b,0,l,r,i});
	}
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	auto id=[&](ll x)->ll {
		return lower_bound(ALL(vals),x)-vals.begin();
	};
	sort(ALL(all)); reverse(ALL(all));
	FT2 ft(SZ(vals));
	for(auto [t,ty,l,r,i]:all)if(ty)ft.fakeUpdate(id(l),-r);
	ft.init();
	vv ans(m);
	for(auto [t,ty,l,r,i]:all){
		if(ty)ft.update(id(l),-r,t);
		else ans[i]=ft.query(id(l)+1,-r+1);
	}
	map<ll,ll> mp;
	fore(i,0,n)mp[ts[i]]=i;
	fore(i,0,m){
		if(ans[i]>=INF-100)ans[i]=-1;
		else ans[i]=mp[ans[i]]+1;
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}