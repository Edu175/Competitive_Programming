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
	vv all;
	fore(i,1,100)all.pb(i);
	fore(i,1,10)fore(j,0,10){
		string s; s.pb('0'+i); s.pb('0'+j);
		fore(k,3,19){
			s.pb((s[SZ(s)-1]+s[SZ(s)-2]-2*'0')%10+'0');
			all.pb(stoll(s));
		}
	}
	sort(ALL(all));
	// imp(all);
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; l--;
		ll res= lower_bound(ALL(all),r)-lower_bound(ALL(all),l);
		cout<<res<<"\n";
	}
	return 0;
}
