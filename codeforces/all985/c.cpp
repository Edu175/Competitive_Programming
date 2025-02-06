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

ll n;
ll a[MAXN];
bool can(ll k, ll fg=0){
	// if(fg)cout<<"can "<<k<<":\n";
	vv voy(n+1),vue(n+1);
	ll x=0;
	fore(i,0,n){
		if(a[i]<x)x--;
		else if(a[i]>x)x++;
		voy[i+1]=x;
	}
	x=k;
	ll mn=k;
	for(ll i=n-1;i>=0;i--){
		if(a[i]>=x)x--;
		else x++;
		// if(fg)cout<<i<<": "<<voy[i]<<" "<<mn<<"\n";
		if(voy[i]>=mn)return 1;
		mn=min(mn,x);
	}
	return 0;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=n+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		// can(3,1);
		cout<<r<<"\n";
	}
	return 0;
}
