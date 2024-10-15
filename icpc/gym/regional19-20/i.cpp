#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXN=2e3+10;
const ll mod=1e9+7;
ll n,l;
vv G[MAXN];
// bool vis[MAXN];
ll C[MAXN];
ll addm(ll a, ll m){
	a+=m;
	return a<mod?a:a-mod;
}
ll dp(ll i){
	ll &r=C[i];
	if(r!=-1) return r;
	if(i>=l) return r=1;
	r=0;
	for(ll j: G[i]){
		r=addm(r,dp(j));
	}
	return r;
}
int main(){ET
	mset(C,-1);
	cin>>n>>l;
	fore(i,0,l){
		ll k; cin>>k;
		while(k--){
			ll a; cin>>a; a--;
			G[i].pb(a);
		}
	}
	ll rta=dp(0);
	ll res=0;
	fore(i,l,n){
		if(C[i]!=-1) res++;
	}
	cout<<rta<<" "<<res<<"\n";
	return 0;
}