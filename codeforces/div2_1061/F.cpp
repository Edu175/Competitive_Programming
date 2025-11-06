#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i+1<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		
		auto get_jk=[&](ll i)->ii { // {-1,-1} if not E
			ll v=a[i];
			if(v<2)return {-1,-1};
			ll j=p[v-1],k=p[v-2];
			if(j>k)swap(j,k);
			if(j<i)return {-1,-1};
			return {j,k};
		};
		
		auto good=[&](ll i){
			return get_jk(i).fst!=-1;
		};
		
		auto mop=[&](ll i, ll j, ll k){
			assert(i<j&&j<k);
			a[i]-=2,a[j]++,a[k]++;
			vv ind={i,j,k};
			for(auto i:ind)p[a[i]]=i;
		};
		
		auto busca=[&](){
			ll p=-1;
			fore(i,0,n)if(good(i))p=i;
			return p;
		};
		
		vv sta;
		fore(i,0,n)if(good(i))sta.pb(i);
		
		while(SZ(sta)){
			imp(a)
			auto i=sta.back();
			assert(i==busca()); // cubic
			auto [j,k]=get_jk(i);
			assert(j!=-1);
			ll v=a[i];
			mop(i,j,k);
			if(!good(i))sta.pop_back();
			vv pon;
			fore(ad,1,3){
				ll u=v+ad;
				if(u>=n)continue;
				ll pos=p[u];
				if(pos>i&&good(pos))pon.pb(pos);
			}
			sort(ALL(pon));
			for(auto i:pon)sta.pb(i);
		}
		assert(busca()==-1);
		
		for(auto i:a)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
