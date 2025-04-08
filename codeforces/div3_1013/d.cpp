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

ll n,m,k;
bool can(ll h){
	ll q=(m/(h+1))*h+m%(h+1);
	return q*n>=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		ll l=0,r=m;
		while(l<=r){
			ll h=(l+r)/2;
			if(can(h))r=h-1;
			else l=h+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
