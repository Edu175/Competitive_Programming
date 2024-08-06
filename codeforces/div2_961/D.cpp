#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		string s; cin>>s;
		vector<ll>oc(m);
		ll mk=0;
		vector<ll>mks;
		fore(i,0,k)oc[s[i]-'A']++,mk|=1ll<<(s[i]-'A');
		vector<ll>bad(1ll<<m);
		auto com=[&](ll mk){return ((1<<m)-1)&~mk;};
		bad[mk]=1;
		fore(i,k,n){
			ll c=s[i-k]-'A'; oc[c]--;
			if(!oc[c])mk^=1ll<<c;
			c=s[i]-'A';
			mk|=1ll<<c;
			oc[c]++;
			bad[mk]=1;
		}
		bad[1ll<<(s.back()-'A')]=1;
		// fore(mk,0,1ll<<m)cout<<mk<<": "<<bad[mk]<<"\n";
		
		fore(j,0,m)fore(mk,0,1ll<<m){
			bad[mk|(1ll<<j)]|=bad[mk];
		}
		// fore(mk,0,1ll<<m)cout<<mk<<": "<<bad[mk]<<"\n";
		ll res=m+5;
		fore(mk,0,1ll<<m)if(!bad[com(mk)])
			res=min(res,(ll)__builtin_popcount(mk));
		cout<<res<<"\n";
	}
	return 0;
}
