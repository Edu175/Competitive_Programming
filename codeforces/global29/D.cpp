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
		map<ll,ll>mp;
		fore(i,0,n){
			ll v; cin>>v;
			mp[v]++;
		}
		ll sum=0;
		vv cand;
		for(auto [w,c]:mp){
			if(w&1){
				cand.pb(c);
				// w--;
			}
			sum+=(w/2)*c;
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		ll a=0,b=0;
		fore(i,0,SZ(cand)){
			if(i&1)b+=cand[i];
			else a+=cand[i];
		}
		a+=sum; b+=sum;
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
