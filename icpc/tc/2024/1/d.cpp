#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e14;

ll n,k;
ii A[MAXN];

bool can(ll x){
	cout<<"\n\ncan "<<x<<"\n";
	vector<ii>h[k+1];
	vector<ii>a;
	fore(i,0,n)a.pb(A[i]);
	auto upd=[&](ll i){
		ll p=a[i].snd/a[i].fst;
		ll v=a[i].snd+p*(-a[i].fst);
		// cout<<"upd "<<i<<" "<<a[i].fst<<","<<a[i].snd<<": "<<p<<" "<<v<<endl;
		if(p<=k)h[p].pb({i,v});
	};
	fore(i,0,n)upd(i);
	if(!x){
		fore(i,0,k+1)if(SZ(h[i]))return 0;
		return 1;
	}
	ll s=0;
	fore(t,1,k+1){
		s++;
		for(auto [i,v]:h[t]){
			assert(v<0);
			ll q=(-v+x-1)/x;
			a[i].snd+=q*x;
			s-=q;
			// cout<<t<<" "<<i<<": "<<q<<" "<<s<<endl;
			upd(i);
			if(s<0)return 0;
		}
	}
	return 1;
}


int main(){JET
	cin>>n>>k;
	fore(i,0,n)cin>>A[i].snd;
	fore(i,0,n)cin>>A[i].fst;
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	if(l>=INF)cout<<"-1\n";
	else cout<<l<<"\n";
}