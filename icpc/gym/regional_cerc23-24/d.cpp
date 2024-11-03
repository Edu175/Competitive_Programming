#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=3e5+5;

int main(){JET
	ll n,q; cin>>n>>q;
	vv d(n);
	vector<ii>ev;
	ll def=0,Lmax=0,tot=0;
	fore(i,0,n){
		ll l,r; cin>>d[i]>>l>>r;
		ev.pb({r,i});
		Lmax=max(Lmax,l);
		def+=d[i];
	}
	ev.pb({Lmax,-1});
	vv ls,ts;
	sort(ALL(ev));
	ll did=0;
	bitset<MAXN>b; b[0]=1;
	auto ff=[&](ll k){
		return b[k]?k:b._Find_next(k);
	};
	for(auto [r,i]:ev){
		if(i!=-1){
			def-=d[i];
			b|=b<<d[i];
			tot+=d[i];
		}
		else did=1;
		if(did){
			ll resi=ff((tot+1)/2)+def;
			ts.pb(r);
			ls.pb(resi);
		}
	}
	while(q--){
		ll li; cin>>li;
		ll l=0,r=SZ(ts)-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(li>=ls[m])r=m-1;
			else l=m+1;
		}
		ll res=l>=SZ(ts)?-1:ts[l];
		cout<<res<<"\n";
	}
    return 0;
}