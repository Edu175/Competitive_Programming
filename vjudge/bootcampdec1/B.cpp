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
const ll MAXN=105;

ll a[MAXN];
ll n,h;

bool messirve(ll k){
	ll d=k;
	if(d>=h)return 1;
	fore(i,0,n-1){
		d+=min(k,a[i+1]-a[i]);
		if(d>=h)return 1;
	}
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>h;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=h+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(messirve(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
