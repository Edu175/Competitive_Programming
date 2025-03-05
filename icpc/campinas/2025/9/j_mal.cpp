#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool check(vv a){
	sort(ALL(a));
	fore(i,0,SZ(a)-1){
		if(a[i+1]-a[i]>1)return 0;
	}
	return 1;
}


int main(){
	JET
	ll n; cin>>n;
	vv xs(n),ys(n),zs(n);
	fore(i,0,n)cin>>xs[i];
	fore(i,0,n)cin>>ys[i];
	fore(i,0,n)cin>>zs[i];
	map<ii,vv>mpz;
	map<ll,vector<ii>>mpy;
	vector<pair<ll,ii>> mpx;
	fore(i,0,n){
		ll x=xs[i],y=ys[i],z=zs[i];
		mpz[{x,y}].pb(z);
		mpy[x].pb({y,z});
		mpx.pb({x,{y,z}});
	}
	
	ll flag=check(xs);
	cout<<"flag "<<flag<<" check\n";
	map<ii,set<ll>>mp;
	for(auto i:mpx)mp[i.snd].insert(i.fst);
	for(auto [ksdjf,st]:mp){
		for(auto i:xs)if(!st.count(i)){flag=0;break;}
	}
	
	cout<<"flag "<<flag<<" xs\n";
	
	for(auto [x,v]:mpy){
		vector<ll>ys;
		map<ll,set<ll>>mp;
		for(auto i:v)ys.pb(i.fst),mp[i.snd].insert(i.fst);
		flag&=check(ys);
		for(auto [ksdjf,st]:mp){
			for(auto i:ys)if(!st.count(i)){flag=0;break;}
		}
	}
	cout<<"flag "<<flag<<" ys\n";
	
	for(auto [xy,v]:mpy){
		vector<ll>zs;
		for(auto i:v)zs.pb(i.fst);
		flag&=check(zs);
	}
	cout<<"flag "<<flag<<" zs\n";
	
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}