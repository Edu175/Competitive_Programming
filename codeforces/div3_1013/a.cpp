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

vv date(10);

int main(){FIN;
	string s="01032025";
	for(auto i:s)date[i-'0']++;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv c(10);
		ll p=-1;
		fore(i,0,n){
			ll x; cin>>x;
			c[x]++;
			ll fg=1;
			fore(i,0,10)fg&=date[i]<=c[i];
			if(fg&&p==-1)p=i;
		}
		cout<<p+1<<"\n";
	}
	return 0;
}
