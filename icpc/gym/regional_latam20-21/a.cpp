#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ET
	ll m,n; cin>>m>>n;
	if(m!=1){cout<<"*\n"; return 0;}
	ll k=63-__builtin_clzll(n),v=1;
	auto go=[&](ll a, ll b){
		cout<<"1 "<<a<<"\n";
		cout<<"1 "<<b<<"\n";
	};
	for(ll j=k-1;j>=0;j--){
		go(v,v); v+=v;
		if(n>>j&1)go(v,1),v++;
	}
	return 0;
}


/*



*/