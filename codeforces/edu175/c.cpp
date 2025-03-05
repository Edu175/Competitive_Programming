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
const ll MAXN=3e5+5;
ll n,k;
string s;
ll a[MAXN];

bool can(ll m){
	vv b;
	fore(i,0,n){
		if(a[i]<=m)b.pb(0);
		else b.pb(s[i]=='R'?-1:1);
	}
	ll hay=0,ki=0;
	fore(i,0,n){
		if(b[i]==1)hay=1;
		if(b[i]==-1)ki+=hay,hay=0;
	}
	ki+=hay;
	return ki<=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k>>s;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=1e9+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
