#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

ll tr[MAXN][8],qidx=1;
ll val[MAXN];
ll add(ll x, ll c){
	auto &ret=tr[x][c];
	if(ret!=-1)return ret;
	return ret=qidx++;
}
ll ans=0,k;
vv v;
void f(ll i, ll x, ll sum){
	if(x==-1)return;
	if(i==k){ans+=val[x];return;}
	fore(va,v[i],9-sum){
		f(i+1,tr[x][va],sum+va);
	}
}

int main(){ET
	mset(tr,-1);
	ll q; cin>>q>>k;
	vector<vv> vs;
	auto get=[&](){
		ll m; cin>>m;
		vv v(k);
		fore(_,0,m){
			ll x; cin>>x; x--;
			v[x]++;
		}
		return v;
	};
	auto upd=[&](ll p, ll va){
		auto v=vs[p];
		ll x=0;
		fore(i,0,k)x=add(x,v[i]);
		val[x]+=va;
	};
	auto query=[&](vv _v){
		v=_v;
		ans=0;
		f(0,0,0);
		return ans;
	};
	while(q--){
		char ty; cin>>ty;
		if(ty=='C'){
			auto v=get();
			vs.pb(v);
			upd(SZ(vs)-1,1);
		}
		if(ty=='D'){
			ll p; cin>>p; p--;
			upd(p,-1);
		}
		if(ty=='J'){
			auto v=get();
			auto res=query(v);
			cout<<res<<"\n";
		}
	}
}