#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll s;
ll f(ll e, ll h){
	// cout<<e<<" "<<h<<" "<<s<<"\n";
	if(h==0){
		if(e&1)return (s&1)^1;
		else {
			ll ne=e/2;
			if(ne<s&&s<=e)return s&1;
			return f(ne,1);
		}
	}
	else {
		ll ne=e/2;
		if(ne<s&&s<=e)return 1;
		return f(ne,0);
	}
}
ll g(ll _s, ll e, ll h){
	s=_s;
	return f(e,h);
}

int main(){JET
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	ll h=0;
	for(ll i=n-1;i>=0;i--){
		h=g(a[i].fst,a[i].snd,h);
	}
	ll ans0=h;
	h=1;
	for(ll i=n-1;i>=0;i--){
		h=g(a[i].fst,a[i].snd,h);
	}
	ll ans1=h;
	cout<<ans0<<" "<<ans1<<"\n";
	return 0;
}