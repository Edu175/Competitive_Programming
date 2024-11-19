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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n<=4)cout<<"-1\n";
		else {
			vv p[2];
			fore(i,1,n+1)if(i!=4&&i!=5)p[i&1].pb(i);
			p[0].pb(4);
			p[1].pb(5); reverse(ALL(p[1]));
			for(auto i:p[0])cout<<i<<" ";
			for(auto i:p[1])cout<<i<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
