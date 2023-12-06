#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll n;
ii a[MAXN];

bool can(ll k){
	ll l=0,r=0;
	fore(i,0,n){
		auto [s,e]=a[i];
		l=max(l-k,s);
		r=min(r+k,e);
		if(l>r)return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll l=0,r=1e10;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
