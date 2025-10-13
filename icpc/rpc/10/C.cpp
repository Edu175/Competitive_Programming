#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll K=60;

int main(){FIN;
	ll n,t; cin>>n>>t;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto simu=[&](ll i, ll v, auto &&simu){
		if(i>=n)return;
		a[i]++; v--;
		if(!v){
			if(a[i]==1)return;
			v=a[i]; a[i]=0;
		}
		simu(i+1,v,simu);
	};
	auto getp=[&]()->ll {
		fore(i,0,n){
			if(i%2==0&&a[i])return i/2;
		}
		return -1;
	};
	while(t){
		ll p=getp();
		ll k=__lg(t);
		if(p!=-1)k=min(k,p);
		assert(t>=(1ll<<k));
		// cout<<t<<": "<<p<<" "<<k<<"\n";
		t-=1ll<<k;
		fore(i,0,k){
			ll pos=2*i+1;
			if(pos>=n)break;
			ll pot=1ll<<(k-1-i);
			a[pos]+=pot;
		}
		simu(2*k,1,simu);
	}
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<"\n";
	// imp(a)
	return 0;
}