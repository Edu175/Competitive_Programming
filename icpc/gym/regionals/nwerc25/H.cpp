#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef unsigned long long ull;
ii f(ll n, ll k, vv good, ull mk){
	// cerr<<n<<" "<<k<<" "<<mk<<": ";
	// for(auto i:good)cout<<i;;cout<<"\n";
	assert(SZ(good)==n);
	vv id;
	fore(i,0,n)if(good[i])id.pb(i);
	// vv par(n,-1);
	// fore(i,0,SZ(id))if(i%2==0&&i+1<SZ(id)){
	// 	par[id[i]]=id[i+1];
	// 	par[id[i+1]]=id[i];
	// }
	vv ons;
	fore(i,0,n)if(mk>>i&1)ons.pb(i);
	reverse(ALL(ons));
	ons.pb(-1);
	ll pri=ons[0];
	ll seg=ons[1];
	vv prox(n);
	map<ll,vv> to;//,vv(n,-1)); // [seg][pri] = to
	fore(i,-1,n)to[i]=vv(n,-1);
	vv now;
	for(ll s=n-2;s>=-1;s--){
		if(good[s+1])now.insert(now.begin(),s+1);
		fore(idx,0,SZ(now)){
			ll p=now[idx];
			auto &res=to[s][p];
			ll j=idx^1;
			if(j>=SZ(now))res=-1;
			else res=now[j];
			if(res==-1){
				assert(p==n-1);
				prox[s]=1;
			}
		}
	}
	if(to[seg][pri]!=-1){
		return {pri,to[seg][pri]};
	}
	assert(pri==n-1);
	prox.pop_back();
	mk^=1ull<<pri;
	return f(n-1,k-1,prox,mk);
}
void locuras(ll pos, ll w){
	cout<<pos/w+1<<" "<<pos%w+1<<"\n";
}

int main(){
	// JET
	ll t; cin>>t;
	while(t--){
		ll h,w,k; cin>>h>>w>>k;
		ull x = 0;
		ll sz = h*w;
		fore(i,0,sz){
			char c; cin>>c;
			if(c== '#') x|=ull(1)<<i;
		}
		if((sz|k)==sz){
			cout<<"risky"<<endl;
			continue;
		}
		auto [f1,f2]=f(sz,k,vv(sz,1),x);
		if(x>>f2&1) swap(f1,f2);
		// cerr<<sz<<": "<<f1<<" "<<f2<<"\n";
		locuras(f1,w);locuras(f2,w);
		cout<<endl;
	}
	return 0;
}